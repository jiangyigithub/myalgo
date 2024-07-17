#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for std::max

enum STOrder {
    EQUAL,
    AHEAD,
    BEHIND
};

struct STBlock {
    int id;
    // 其他属性可以在此添加
};

class PartialOrderedGraph {
private:
    std::vector<std::vector<STOrder>> graph;
    std::vector<int> indegree;
    int numNodes;

public:
    PartialOrderedGraph(int N) : numNodes(N) {
        graph.resize(N, std::vector<STOrder>(N, EQUAL));
        indegree.resize(N, 0);
    }

    void AddRelation(int i, int j, STOrder order) {
        graph[i][j] = order;
        if (order == BEHIND) {
            indegree[j]++;
        }
    }

    std::vector<int> LongestOrderedChain(STOrder orderConstraint) {
        std::vector<int> longestChain;
        std::queue<int> searchQueue;

        // 初始化搜索队列，将所有入度为0的节点加入
        for (int i = 0; i < numNodes; ++i) {
            if (indegree[i] == 0) {
                searchQueue.push(i);
            }
        }

        while (!searchQueue.empty()) {
            int current = searchQueue.front();
            searchQueue.pop();
            longestChain.push_back(current);

            // 扩展当前节点的邻居节点
            for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
                if (graph[current][neighbor] == orderConstraint) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        searchQueue.push(neighbor);
                    }
                }
            }
        }

        return longestChain;
    }
};

int main() {
    int N = 4; // 假设有4个STBlock

    PartialOrderedGraph poGraph(N);

    // 假设我们有以下关系
    poGraph.AddRelation(0, 1, BEHIND);
    poGraph.AddRelation(1, 2, AHEAD);
    poGraph.AddRelation(0, 2, BEHIND);
    poGraph.AddRelation(2, 3, BEHIND);

    std::vector<int> longestChain = poGraph.LongestOrderedChain(BEHIND);

    std::cout << "Longest ordered chain (BEHIND): ";
    for (int node : longestChain) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}
