#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // dp[i] stores the maximum amount that can be robbed from houses [start...i]
    // time complexity : O(2n) = O(n) each position is calcualted only once , twice for subStart and subEnd
    // space complexity : O(n) , dp of size n , we reuse the same space + recursion stack
    // slightly different approach from the previous memoisation and recursion we have done. you can use either one.
    int robSum(vector<int>& nums, int n,int start,vector<int>& dp){
        if(n<start) return 0;
        if(dp[n]!=-1) return dp[n];
        // either take the current element then start from n-2 or abandon it and start from n-1
        return dp[n]=max(nums[n]+robSum(nums,n-2,start,dp),robSum(nums,n-1,start,dp));
    }
    int rob(vector<int>& nums) {
        // method 1 : recursion
        // methdo 2: dp memoization
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        int subStart = robSum(nums,n-2,0,dp);
        dp = vector<int>(n,-1); //reset dp
        int subEnd = robSum(nums,n-1,1,dp);
        return max(subStart,subEnd);
    }
};
int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // example input
    Solution sol;
    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}
