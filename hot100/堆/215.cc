class Solution {
         int dfs(vector<int>& nums, int k) {
            vector<int> greater, equal, less;
            int n = nums.size();
            int pivot = nums[rand() % n];
            for (auto num : nums) {
                if (num < pivot)
                    less.push_back(num);
                else if (num == pivot)
                    equal.push_back(num);
                else
                    greater.push_back(num);
            }

            int left = greater.size(), mid = equal.size(), right = less.size();

            if (k <= left) {
                return dfs(greater, k);
            }

            if (k > (left + mid)) {
                return dfs(less, k-(left+mid));
            }
            // mid;
            return pivot;
        }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return dfs(nums,k);
    }
};