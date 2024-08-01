#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{

    // 值 0 代表空单元格；
    // 值 1 代表新鲜橘子；
    // 值 2 代表腐烂的橘子。
    // 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

public:

    int orangesRotting(vector<vector<int>> &grid)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        int fresh = 0, rot = 0;
        int ans =0 ;
        vector<pair<int, int>> cur, DIRECTION = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j]==2)
                {
                    rot++;
                    cur.push_back({i, j}); // 第一轮腐烂的橘子
                }
            }
        }

        if (fresh == 0) return 0;

        while (!cur.empty())
        {  
            vector<pair<int, int>>  nxt;
            //遍历当前层
            for (int i = 0; i<cur.size(); i++)
            {
                auto e = cur[i];
                /// 遍历子树
                for (auto c : DIRECTION)
                {
                    int m = e.first + c.first;
                    int n = e.second + c.second;
                    if ((m >= 0 && m < nr) && (n >= 0 && n < nc) && grid[m][n] == 1)
                    {
                        fresh--;
                        grid[m][n] = 2;
                        nxt.push_back({m, n});
                    }
                }
            }
            if (nxt.empty())
            {
                break;
            }
            cur = nxt;
            ans++;
        }

        return fresh > 0 ? -1 : ans;
    }
};

// Structure to hold test case information
struct TestCase
{
    vector<vector<int>> grid;
    int expected;

    TestCase(vector<vector<int>> grid, int expected) : grid(grid), expected(expected) {}
};

// Function to run test cases
void runTests()
{
    // Create test cases
    vector<TestCase> testCases;

    testCases.push_back(TestCase{{ {2, 1, 1}, {1, 1, 0}, {0, 1, 1} }, 4});
    testCases.push_back(TestCase{{ {2, 1, 1}, {0, 1, 1}, {1, 0, 1} }, -1});
    testCases.push_back(TestCase{{ {0, 2} }, 0});
    testCases.push_back(TestCase{{ {2, 2, 2, 1, 1}, {1, 1, 1, 1, 2}, {2, 2, 1, 2, 1} }, 2});

    Solution sol;
    for (size_t i = 0; i < testCases.size(); ++i)
    {
        int result = sol.orangesRotting(testCases[i].grid);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Expected Result: " << testCases[i].expected << "\n";
        cout << "Actual Result: " << result << "\n";
        cout << "Test " << (result == testCases[i].expected ? "Passed" : "Failed") << "\n\n";
    }
}

int main()
{
    runTests();
    return 0;
}

