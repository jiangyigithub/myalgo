#include <vector>
#include <iostream>
#include <algorithm> // for std::min
using namespace std;
// {{1, 2, 5}, 11, 3},     // Test case 1: 11 can be made with 5 + 5 + 1
// {{2}, 3, -1},           // Test case 2: 3 cannot be made with only coin 2
// {{1, 2, 5}, 0, 0},      // Test case 3: 0 can be made with no coins
// {{1}, 2, 2},            // Test case 4: 2 can be made with two 1 coins
// {{2}, 1, -1},           // Test case 5: 1 cannot be made with only coin 2
// {{1, 2, 5, 10}, 27, 4}  // Test case 6: 27 can be made with 10 + 10 + 5 + 2
11--> 5 5 1

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0; // 凑成0金额所需硬币数量为0

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

struct TestCase {
    vector<int> coins;
    int amount;
    int expected;
};

int main() {
    vector<TestCase> testCases = {
        {{1, 2, 5}, 11, 3},     // Test case 1: 11 can be made with 5 + 5 + 1
        {{2}, 3, -1},           // Test case 2: 3 cannot be made with only coin 2
        {{1, 2, 5}, 0, 0},      // Test case 3: 0 can be made with no coins
        {{1}, 2, 2},            // Test case 4: 2 can be made with two 1 coins
        {{2}, 1, -1},           // Test case 5: 1 cannot be made with only coin 2
        {{1, 2, 5, 10}, 27, 4}  // Test case 6: 27 can be made with 10 + 10 + 5 + 2
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& testCase = testCases[i];
        int result = coinChange(testCase.coins, testCase.amount);
        cout << "Test case " << i + 1 << ": expected = " << testCase.expected << ", got = " << result;
        if (result == testCase.expected) {
            cout << " [PASSED]" << endl;
        } else {
            cout << " [FAILED]" << endl;
        }
    }

    return 0;
}
