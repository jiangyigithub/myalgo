class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left =0,right=n-2;
        while(left<=right){
            int mid = left+(right-left)/2;            
            if(nums[mid]>nums[n-1]){
                left = mid+1; // mid右移
            }
            else{
                right = mid-1; // mid左移
            }
        }
        return left;
    }
};