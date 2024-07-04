/*
递推表达式:dp[i]=min(dp[i],dp[i-coin]+1)
dp参数:i金额,coin硬币
dp初值:初始值dp[0],输出0
第一次更新的条件：[3,4,5] aim是20
    如果 aim是3， 输出为1
    如果 aim是4， 输出为1
    如果 aim是5， 输出为1
if(i-coin >=0)，dp[3] = 0+1,dp[4]= 0+1,dp[5]=0+1,保证dp第一次更新正确
*/

/*
总结
0. dp递推表达式是什么？ --> dp[i]=min(dp[i],dp[i-coin]+1)
1. dp的参数是什么？ --> i金额,coin硬币
2. dp的初值是什么？ --> dp[0]=0
3. dp第一次更新的条件是什么？ --> if(i-coin >=0)
*/
#include <vector>
#include <iostream>
#include <algorithm> // for std::min
using namespace std;
int coinChange(const vector<int>& coins, int amount)
{
    vector<int> dp(amount+1,amount+1);
    dp[0]=0;
    for(int i=1;i<=amount;++i){
        for(int coin:coins){
            if(i-coin >=0)
                dp[i]=min(dp[i],dp[i-coin]+1);
        }
    }
    return dp[amount]== amount+1? -1:dp[amount];
}

struct TestCase {
    vector<int> coins;
    int amount;
    int expected;
};

int main() {
    TestCase testCases[] = {
        {{5,4,3},20,4},
        {{1, 2, 5}, 11, 3},     // Test case 1: 11 can be made with 5 + 5 + 1
        {{2}, 3, -1},           // Test case 2: 3 cannot be made with only coin 2
        {{1, 2, 5}, 0, 0},      // Test case 3: 0 can be made with no coins
        {{1}, 2, 2},            // Test case 4: 2 can be made with two 1 coins
        {{2}, 1, -1},           // Test case 5: 1 cannot be made with only coin 2
        {{1, 2, 5, 10}, 27, 4}  // Test case 6: 27 can be made with 10 + 10 + 5 + 2
    };

    for (size_t i = 0; i < 6; ++i) {
        const TestCase& testCase = testCases[i];
        vector<int> temp = testCase.coins;
        int result = coinChange(temp, testCase.amount);
        cout << "Test case " << i + 1 << ": expected = " << testCase.expected << ", got = " << result;
        if (result == testCase.expected) {
            cout << " [PASSED]" << endl;
        } else {
            cout << " [FAILED]" << endl;
        }
    }

    return 0;
}
