#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution 
{

    
public:
vector<int> sorted;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // 初始化入度数组和邻接表
        vector<int> indegrees(numCourses);
        vector<vector<int>> adjacency(numCourses);
        queue<int> que;

        // 建立入度数组和邻接表
        for (auto& cp : prerequisites)
        {
            indegrees[cp[0]]++;  // cp[0] 入度
            adjacency[cp[1]].push_back(cp[0]);
        }

        // 将所有入度为0的节点加入队列
        for (int i = 0; i < numCourses; i++)
        {
            if (indegrees[i] == 0)
            {
                que.push(i);
            }
        }

        // 拓扑排序
        
        while (!que.empty())
        {
            int cur = que.front();
            sorted.push_back(cur);
            que.pop();
            numCourses--;
            for (auto nxt : adjacency[cur])
            {
                if (--indegrees[nxt] == 0)
                {
                    que.push(nxt);
                }
            }
        }

        // 如果所有课程都能完成，则返回true
        return numCourses == 0;
    }
};

// 测试用例结构体
struct TestCase {
    int numCourses;
    vector<vector<int>> prerequisites;
    bool expected;
};

void runTests() {
    // 定义测试用例
    // # 0          邻接表
    // #    \       下标  0     1     2     3    4    5   同时也表示要先学的课程
    // #    /  3        [3]  [3,4]  [4]   [5]  [5]  [ ]  学完上面的课程才能学的课程，例如学完0才能学3，学完1才能学3和4
    // # 1        \
    // #    \     /  5     这个邻接表的创建是通过        for(int[] cp : prerequisites)
    // #       4                                           adjacency.get(cp[1]).add(cp[0]);         实现的
    // #    /  
    // # 2
    vector<TestCase> testCases = {
        {6,{{3,0},{3,1},{4,1},{4,2},{5,3},{5,4}},true},
        // {2, {{1, 0}}, true},
        // {2, {{1, 0}, {0, 1}}, false},
        // {4, {{1, 0}, {2, 1}, {3, 2}}, true},
        // {3, {{0, 1}, {0, 2}, {1, 2}}, true},
        // {3, {{0, 1}, {1, 2}, {2, 0}}, false}
    };

    Solution solution;
    for (int i = 0; i < testCases.size(); i++) {
        TestCase& tc = testCases[i];
        bool result = solution.canFinish(tc.numCourses, tc.prerequisites);
        cout << "Test Case " << i + 1 << ": " << endl;
        cout << "Number of Courses: " << tc.numCourses << endl;
        cout << "Prerequisites: [";
        for (int j = 0; j < tc.prerequisites.size(); j++) {
            if (j > 0) cout << ", ";
            cout << "[" << tc.prerequisites[j][0] << ", " << tc.prerequisites[j][1] << "]";
        }
        cout << "]" << endl;
        cout << "sorted result: " ;
        for(auto e:solution.sorted){
            cout<< e <<  ", ";
        }
        cout << "Expected Result: " << (tc.expected ? "true" : "false") << endl;
        cout << "Actual Result: " << (result ? "true" : "false") << endl;
        cout << "Test " << (result == tc.expected ? "PASSED" : "FAILED") << endl << endl;
    }
}

int main() {
    runTests();
    return 0;
}
