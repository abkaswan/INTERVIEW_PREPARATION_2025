#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // time complexity : O(2n) = O(n) each position is calcualted only once , twice for subStart and subEnd
    // space complexity : O(n) , dp of size n , we reuse the same space + recursion stack
    int robHouse(vector<int>& nums,int n,int start,vector<int>& dp){
        if(n<start) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=nums[n]+max(robHouse(nums,n-2,start,dp),robHouse(nums,n-3,start,dp));
    }
    int helper(vector<int>& nums,int n, int start, vector<int>& dp){
        // so for subarray 0 to n-2 it will take n-2 and n-3
        // for subarray 1 to n-1 it will take n-1 and n-2 to perform the robSum function
        return max(robHouse(nums,n,start,dp),robHouse(nums,n-1,start,dp));
    }
    int rob(vector<int>& nums) {
        // method 2 : memoization
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        int subStart = helper(nums,n-2,0,dp);
        dp = vector<int>(n,-1); //Reset dp
        int subEnd = helper(nums,n-1,1,dp);
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
