#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);//nums[left] 
                left++;
            }
            right++;
        }
    }
};



int main() {
    Solution solution;
    vector<int> nums = {0,1,0,3,12};
    solution.moveZeroes(nums);
    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}