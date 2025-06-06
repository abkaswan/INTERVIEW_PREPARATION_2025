#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // time complexity : O(2^n)
    // space complexity : O(n)
    int robSum(vector<int>& nums, int n,int start){
        if(n<start) return 0;
        // either take the current element then start from n-2 or abandon it and start from n-1
        return max(nums[n]+robSum(nums,n-2,start),robSum(nums,n-1,start));
    }
    int rob(vector<int>& nums) {
        // method 1 : recursion
        int n = nums.size();
        if(n==1) return nums[0];
        int subStart = robSum(nums,n-2,0);
        int subEnd = robSum(nums,n-1,1);
        return max(subStart,subEnd);
    }
};
int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution sol;
    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}
