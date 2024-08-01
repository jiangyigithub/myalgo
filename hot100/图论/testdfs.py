def all_topological_sorts(graph):
    def dfs(graph, in_degree, path, visited, res):
        # 当路径长度等于图中的节点数时，保存当前路径（一个拓扑排序）
        if len(path) == len(graph):
            res.append(path.copy())
            return
        
        # 尝试每一个入度为0且未访问的节点
        for node in graph:
            if in_degree[node] == 0 and not visited[node]:
                # 标记为访问过
                visited[node] = True
                path.append(node)
                
                # 减少相邻节点的入度
                for neighbor in graph[node]:
                    in_degree[neighbor] -= 1
                
                # 递归访问
                dfs(graph, in_degree, path, visited, res)
                
                # 回溯
                visited[node] = False
                path.pop()
                for neighbor in graph[node]:
                    in_degree[neighbor] += 1

    # 计算所有节点的入度
    in_degree = {u: 0 for u in graph}
    for u in graph:
        for v in graph[u]:
            in_degree[v] += 1

    visited = {u: False for u in graph}
    res = []
    dfs(graph, in_degree, [], visited, res)
    return res

# 创建更复杂的图

# 0          邻接表
#    \       下标  0     1     2     3    4    5   同时也表示要先学的课程
#    /  3        [3]  [3,4]  [4]   [5]  [5]  [ ]  学完上面的课程才能学的课程，例如学完0才能学3，学完1才能学3和4
# 1        \
#    \     /  5     这个邻接表的创建是通过        for(int[] cp : prerequisites)
#       4                                           adjacency.get(cp[1]).add(cp[0]);         实现的
#    /  
# 2
graph = {
    0: [3],
    1: [3, 4],
    2: [4],
    3: [5],
    4: [5],
    5: []
}

# 获取所有拓扑排序结果
all_top_orders = all_topological_sorts(graph)
for order in all_top_orders:
    print(order)
