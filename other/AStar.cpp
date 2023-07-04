#include <vector>
#include<limits>
#include<queue>
#include<iostream>

void print(int s, int e, const std::vector<int> &parent) {
    if (s == e) return;
    print(s, parent[e], parent);
    std::cout << "->" << e ;
}

double hManhattan(double x1, double y1, double x2, double y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

class AStarGraph {
public:
    AStarGraph(int v_count)
        : v_count_(v_count) {
        adj_ = std::vector<std::vector<Edge>>(v_count, std::vector<Edge>{});
        vertexes = std::vector<Vertex>(v_count);
    }

    void addEdge(int s, int e, double w);

    void addVertex(int id, double x, double y);

    void AStar(int s, int e);

private:
    struct Edge { // 表示边
        int sid_; // 边的起始节点
        int eid_; // 边的结束节点
        double w_;   // 边的权重
        Edge() = default;
        Edge(int s, int e, double w)
                : sid_(s), eid_(e), w_(w) {}
    };
    struct Vertex { // 算法实现中，记录第一个节点到这个节点的距离
        int id_;
        double dist_;
        double f_;      // f(i)=g(i)+h(i)
        double x_, y_;   // 顶点在地图中的坐标（x, y）
        Vertex() = default;
        Vertex(int id, double x, double y)
            : id_(id), x_(x), y_(y)
            , dist_(std::numeric_limits<double>::max())
            , f_(std::numeric_limits<double>::max()) {}
    };
    std::vector<std::vector<Edge>> adj_;    // 邻接表
    int v_count_;                           // 顶点数
    std::vector<Vertex> vertexes;           // 记录所有顶点，主要记录坐标
};


void AStarGraph::addEdge(int s, int e, double w) {
    if (s < v_count_ && e < v_count_) {
        adj_[s].emplace_back(s, e, w) ;
    }
}

void AStarGraph::addVertex(int id, double x, double y) {
    if (id < v_count_) {
        vertexes[id] = Vertex(id, x, y);
    }
}

void AStarGraph::AStar(int s, int e) {
    // 与 Dijkstra 的区别主要在以下几点:
    // 1、优先队列的构建方式不同，A* 算法是使用代码中public int f;这个值来构建的，而 Dijkstra 算法是用 dist 值构建的
    // 2、A* 算法除了需要更新 dist 值，还需要更新 f 值。
    // 3、A* 算法循环结束的条件是只要遍历到终点即退出循环，因此 A* 算法最终并不一定能得到最短路径。
    std::vector<int> parent(v_count_); // 用于还原最短路径, 当前点最短路径的父节点
    struct cmp {
        bool operator() (const Vertex &v1, const Vertex &v2) { return v1.f_ > v2.f_;}
    };
    // 小顶堆
    std::priority_queue<Vertex, std::vector<Vertex>, cmp> queue;
    // 标记是否已找到最短距离
    std::vector<bool> shortest(v_count_, false);

    // 起始节点初始化
    vertexes[s].dist_ = 0;
    vertexes[s].f_ = 0;
    queue.push(vertexes[s]);
    while (!queue.empty()) {
        Vertex minVertex = queue.top();
        queue.top();
        if (minVertex.id_ == e) { break; }
        if (shortest[minVertex.id_]) { continue; } // 之前更新过，是冗余备份
        shortest[minVertex.id_] = true;
        for (int i = 0; i < adj_[minVertex.id_].size(); ++i) {
            Edge cur_edge = adj_[minVertex.id_].at(i); // 取出当前连通的边
            int next_vid = cur_edge.eid_;
            if (minVertex.dist_ + cur_edge.w_ < vertexes[next_vid].dist_) {
                vertexes[next_vid].dist_ = minVertex.dist_ + cur_edge.w_;
                vertexes[next_vid].f_ = vertexes[next_vid].dist_ +
                                        hManhattan(vertexes[next_vid].x_, vertexes[next_vid].y_,
                                                   vertexes[e].x_, vertexes[e].y_);
                parent[next_vid] = minVertex.id_;
                queue.push(vertexes[next_vid]);
            }
        }
    }
    std::cout << s;
    print(s, e, parent);
}

void testAStar()
{
    AStarGraph g{6};
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 12);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 2, 9);
    g.addEdge(3, 2, 4);
    g.addEdge(3, 4, 13);
    g.addEdge(2, 4, 5);
    g.addEdge(4, 5, 4);
    g.addEdge(3, 5, 15);
    g.AStar(0, 5);
}

int main()
{
    testAStar();
}