#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int robSum(vector<int>& nums, int n,vector<int>& dp){
        if(n<0) return 0;
        if(n==0 || n==1) return nums[n];
        if(dp[n]!=-1) return dp[n];
        return dp[n]=nums[n]+max(robSum(nums,n-2,dp),robSum(nums,n-3,dp));
        
    }
    int rob(vector<int>& nums) {
        // recursive apporoach : O(2^n)
        // method 2 : trying top to bottom -- memoization
        int n = nums.size();
        vector<int> dp(n,-1);
        return max(robSum(nums,n-1,dp),robSum(nums,n-2,dp));

    }
};
int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // example input
    Solution sol;
    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}

