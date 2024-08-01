#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to hold test case information
struct TestCase
{
    vector<vector<int>> grid;
    int expected;

    TestCase(vector<vector<int>> grid, int expected) : grid(grid), expected(expected) {}
};

// Solution class with the function to solve the problem
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return -1;

        int rows = grid.size();
        int cols = grid[0].size();
        int freshCount = 0;
        queue<pair<int, int>> rottenQueue;
        
        // Directions array for the 4 possible directions of movement (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    rottenQueue.push({r, c});
                } else if (grid[r][c] == 1) {
                    ++freshCount;
                }
            }
        }
        
        // If there are no fresh oranges, return 0
        if (freshCount == 0) return 0;
        
        int minutes = 0;
        
        // Perform BFS to rot adjacent fresh oranges
        while (!rottenQueue.empty()) {
            ++minutes;
            int currentSize = rottenQueue.size();
            
            for (int i = 0; i < currentSize; ++i) {
                auto [row, col] = rottenQueue.front();
                rottenQueue.pop();
                
                for (const auto& dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;
                    
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        --freshCount;
                        rottenQueue.push({newRow, newCol});
                    }
                }
            }
        }
        
        // If there are still fresh oranges left, return -1
        return freshCount == 0 ? minutes - 1 : -1;
    }
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
