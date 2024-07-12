#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;
double getMid(vector<int>& nums){
    int len = nums.size();
        if (len % 2 != 0)
    {
        return nums[(len + 1) / 2-1 ];
    }
    else
    {
        return (nums[len/2-1] + nums[len/2]) / 2.0;
    }

}
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{    
    int i = 0;
    int j = 0;
    int k = 0;
    if(nums1.size()==0 &&nums2.size()!=0 ){
        return getMid(nums2);
    }
    if(nums1.size()!=0 &&nums2.size()==0 ){
        return getMid(nums1);
    }
    int len = nums1.size() + nums2.size() ;
    vector<int> nums(len,0);
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            nums[k] = nums1[i];
            i++;
        }
        else
        {
            nums[k] = nums2[j];
            j++;
        }
        k++;
    }
    while (i < nums1.size())
    {
        nums[k] = nums1[i];
        i++;
        k++;
    }
    while (j < nums2.size())
    {
        nums[k] = nums2[j];
        j++;
        k++;
    }
    return getMid(nums);


}



// Helper function to run test cases
void runTestCase(vector<int> &nums1, vector<int> &nums2, double expected)
{

    double result = findMedianSortedArrays(nums1, nums2);
    cout << "Test passed. Expected: " << expected << ", Got: " << result << endl;
}

int main()
{
    // Test cases that should pass
    vector<int> nums1_1 = {1, 3};
    vector<int> nums2_1 = {2};
    runTestCase(nums1_1, nums2_1, 2.0);

    vector<int> nums1_2 = {1, 2};
    vector<int> nums2_2 = {3, 4};
    runTestCase(nums1_2, nums2_2, 2.5);

    vector<int> nums1_3 = {0, 0};
    vector<int> nums2_3 = {0, 0};
    runTestCase(nums1_3, nums2_3, 0.0);

    vector<int> nums1_4 = {};
    vector<int> nums2_4 = {1};
    runTestCase(nums1_4, nums2_4, 1.0);

    vector<int> nums1_5 = {2};
    vector<int> nums2_5 = {};
    runTestCase(nums1_5, nums2_5, 2.0);

    vector<int> nums1_6 = {1, 3, 8};
    vector<int> nums2_6 = {7, 9, 10, 11};
    runTestCase(nums1_6, nums2_6, 8); 
}
