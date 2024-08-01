from collections import deque

def topological_sort(graph):
    # graph 是一个邻接表表示的DAG，例如：{0: [1, 2], 1: [3], 2: [3], 3: []}
    in_degree = {u: 0 for u in graph}  # 初始化所有顶点的入度为0
    for u in graph:
        for v in graph[u]:
            in_degree[v] += 1  # 计算每个顶点的入度

    queue = deque([u for u in graph if in_degree[u] == 0])  # 将所有入度为0的顶点加入队列
    top_order = []  # 用于存储拓扑排序的结果

    while queue:
        u = queue.popleft()
        top_order.append(u)
        for v in graph[u]:
            in_degree[v] -= 1  # 对每个邻接顶点入度减1
            if in_degree[v] == 0:
                queue.append(v)  # 如果入度为0，则加入队列

    if len(top_order) == len(graph):
        return top_order  # 如果所有顶点都被处理，返回拓扑排序结果
    else:
        return "Graph has a cycle"  # 否则，说明图中有环

# 示例图
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

print(topological_sort(graph))  # 输出: [0, 1, 2, 3] 或 [0, 2, 1, 3]
