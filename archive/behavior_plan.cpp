///
/// \brief searchOverHorizon Performs an A* search over a limited horizon and returns cost of optimal path
/// \param [in]  horizon                    search horizon in terms of number of discreet steps
/// \param [in]  start                      initial graph node
/// \param [in]  search_function_interface  query functions for graph nodes
/// \param [in]  keep_going_flag            interrupt flag for terminating the search early
/// \param [out] optimal_sequence_cost      the total cost (ctc+ctg_horizon) of the optimal sequence
/// \param [out] optimal_sequence           the optimal sequence of graph nodes
/// \param [out] explored_search_tree       the explored behavioral search tree
/// \return std::error_code
///
template <class Node>
std::error_code searchOverHorizon(const size_t& horizon,
                                  const Node& start,
                                  const SearchFunctionInterface<Node>& search_function_interface,
                                  const std::atomic<bool>& keep_going_flag,
                                  std::vector<BehaviorSearchSequenceResult<Node>>& sequences,
                                  SearchTree<Node>& explored_search_tree)
{
  typedef HorizonNodeInfo<Node> HorizonNode;

  sequences.clear();

  // intermediate results
  Real optimal_sequence_cost;
  std::deque<Node> optimal_sequence;

  // define external comparison function for the priority queue (greater than because we want min elem)
  auto node_compare = [&search_function_interface](const HorizonNode& a, const HorizonNode& b) -> bool {
    return search_function_interface.getTotCost(a.node) > search_function_interface.getTotCost(b.node);
  };

  // list of all currently known behaviors
  std::priority_queue<HorizonNode, std::vector<HorizonNode>, decltype(node_compare)> open_list(node_compare);

  Int64 last_id = 0;

  // add root node to the open list
  explored_search_tree.root_id = ++last_id;
  open_list.emplace(HorizonNode{explored_search_tree.root_id, start, horizon, -1, -1, {}, false});

  while (!open_list.empty())
  {
    // check for interrupt
    if (!keep_going_flag)
    {
      X_WARN("[Behavioral Planner::HorizonA*] behavioral search interrupted");
      auto err = behavioral_planner_error_codes::emit_for_a_star_interruption();
      X_OCCURRED_RETURN_ERROR(err);
    }

    // pop the lowest cost node of the open list
    auto top_horizon_node = open_list.top();

    Int64 current_id = top_horizon_node.id;
    Int64 current_core_parent_id = top_horizon_node.core_parent_id;
    auto itInserted = explored_search_tree.map.insert({current_id, std::move(top_horizon_node)}).first;
    open_list.pop();
    assert(itInserted->first == current_id);
    HorizonNode& curr_horizon_node = itInserted->second;
    curr_horizon_node.was_expanded = true;
    Node& curr_node = curr_horizon_node.node;
    const size_t& curr_horizon = curr_horizon_node.horizon;

    if (curr_horizon == 0)
    {
      optimal_sequence.clear();
      // opened the lowest cost node that reaches the horizon -> found optimal sequence
      optimal_sequence_cost = search_function_interface.getTotCost(curr_node);
      Int64 curr_parent_id = curr_horizon_node.parent_id;
      HorizonNode* current_node = &curr_horizon_node;
      assert(-1 != curr_parent_id);
      while (-1 != curr_parent_id)
      {
        optimal_sequence.push_front(current_node->node);
        current_node = &explored_search_tree.map.at(current_node->parent_id);
        curr_parent_id = current_node->parent_id;
      }

      ignoreOrAddSequence(optimal_sequence, optimal_sequence_cost, start.relevant_stop_id, sequences);

      // TODO: change termination criterion?
      if (sequences.size() == 2) // desired number of behaviors
      {
        // desired number of behaviors found, no further action required
        break;
      }
      else
      {
        // prune all leafs on currently used branch, but keep all other explored leafs
        // sligthly complicated, because priority_queue does not directly allow erase()
        std::vector<HorizonNode> remaining_nodes; // helper storage
        while (!open_list.empty())
        {
          auto& horizon_node = open_list.top();
          if (horizon_node.core_parent_id != current_core_parent_id)
            remaining_nodes.emplace_back(horizon_node);
          open_list.pop();
        }

        for (auto& horizon_node : remaining_nodes)
          open_list.push(horizon_node);

        // do not add the succesors of this node to the open_list
        continue;
      }
    }

    // skip this node if state is already visited, else register as visited and continue
    bool visited;
    auto err = search_function_interface.checkVisited(curr_node, visited);
    X_PROPAGATED_RETURN_IF_ERROR(err);
    if (visited)
    {
      continue;
    }

    // identify possible successors to the current node
    std::vector<Node> successors;
    err = search_function_interface.findSuccessors(horizon - curr_horizon, curr_node, successors);
    if (err)
    {
      curr_node.failed = true;
      curr_node.introspection_data.failure_msg = err.message();
      X_HANDLED_IF_ERROR(err);
      continue; // just prune this leaf and continue
    }

    // add each successor to the open list
    curr_horizon_node.children_ids.reserve(successors.size());
    Int64 core_parent_id = current_core_parent_id;
    for (auto& successor_node : successors)
    {
      ++last_id; // id of new node

      if (current_core_parent_id == -1) // define this as core_parent, if last node was the root
        core_parent_id = last_id;

      HorizonNode node{last_id, std::move(successor_node), curr_horizon - 1, current_id, core_parent_id, {}, false};

      if (!successor_node.failed)
      {
        // add to the open list
        open_list.push(node);
      }
      else
      {
        explored_search_tree.map.insert({node.id, std::move(node)});
      }
      curr_horizon_node.children_ids.push_back(last_id);
    }
  }

  // convert rest of open list to beh_search_tree_info
  // this is only needed, to be able to send introspection data (for visual debugging)
  // this is not needed for the functionality of the algorithm itself
  while (!open_list.empty())
  {
    auto& temp_horizon_node = open_list.top();
    explored_search_tree.map.insert({temp_horizon_node.id, std::move(temp_horizon_node)});
    open_list.pop();
  }

  return std::error_code();
}
