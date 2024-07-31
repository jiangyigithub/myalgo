#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    int DIRECTIONS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 四方向

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++; // 统计新鲜橘子个数
                } else if (grid[i][j] == 2) {
                    q.emplace_back(i, j); // 一开始就腐烂的橘子
                }
            }
        }

        int ans = -1;
        while (!q.empty()) {
            ans++; // 经过一分钟
            vector<pair<int, int>> nxt;
            for (auto& [x, y] : q) { // 已经腐烂的橘子
                for (auto d : DIRECTIONS) { // 四方向
                    int i = x + d[0], j = y + d[1];
                    if (0 <= i && i < m && 0 <= j && j < n && grid[i][j] == 1) { // 新鲜橘子
                        fresh--;
                        grid[i][j] = 2; // 变成腐烂橘子
                        nxt.emplace_back(i, j);
                    }
                }
            }
            q = move(nxt);
        }

        return fresh ? -1 : max(ans, 0);// 最后如果发现 fresh>0，就意味着有橘子永远不会腐烂，返回 −1
    }
};

// Structure to hold test case information
struct TestCase {
    vector<vector<int>> grid;
    int expected;

    TestCase(vector<vector<int>> grid, int expected) : grid(grid), expected(expected) {}
};

// Function to run test cases
void runTests() {
    // Create test cases
    vector<TestCase> testCases;

    testCases.emplace_back(vector<vector<int>>{{2,1,1},{1,1,0},{0,1,1}}, 4);
    testCases.emplace_back(vector<vector<int>>{{2,1,1},{0,1,1},{1,0,1}}, -1);
    testCases.emplace_back(vector<vector<int>>{{0,2}}, 0);
    testCases.emplace_back(vector<vector<int>>{{2,2,2,1,1},{1,1,1,1,2},{2,2,1,2,1}}, 2);

    Solution sol;
    for (size_t i = 0; i < testCases.size(); ++i) {
        int result = sol.orangesRotting(testCases[i].grid);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Expected Result: " << testCases[i].expected << "\n";
        cout << "Actual Result: " << result << "\n";
        cout << "Test " << (result == testCases[i].expected ? "Passed" : "Failed") << "\n\n";
    }
}

int main() {
    runTests();
    return 0;
}
