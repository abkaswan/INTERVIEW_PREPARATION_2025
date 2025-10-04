// Subset-sum style DP
//     State: (i, currentSum)
//     i = which element we are at
//     currentSum = sum of elements already chosen
// This uniquely identifies the subproblem:
// “Can we form a subset with sum target using elements from i to n-1, given that the sum we already picked is currentSum?”
// so for Recursive DP → “I’ve walked this far, how much distance have I already covered?”

#include<iostream>
#include<vector>
using namespace std;
// time complexity :  O(n*sum) , space complexity : O(n*sum) + O(n) for recursion stack
class Solution {
public:
    bool checkPartition(int i,vector<int>& nums,int sum1,int target,vector<vector<int>>& dp){
        if(sum1 == target) return true;
        if(i==nums.size() || sum1>target){
            return false;
        }
        if(dp[i][sum1]!=-1) return dp[i][sum1];
        // two choices either include current element for sum1 or not include
        return dp[i][sum1] = checkPartition(i+1,nums,sum1+nums[i],target,dp) || checkPartition(i+1,nums,sum1,target,dp);
    }
    bool canPartition(vector<int>& nums) {
        // method 3 : recursion with memoization
        // we need sum1 and sum2 to be equal that means sum1+sum2 = totalSum  --> 2*sum1 = totalSum;
        // sum1 = totalSum/2 so if we do it for sum1 = target then it works
        int totalSum = 0;
        for(auto x : nums) totalSum+=x;
        if (totalSum % 2 != 0) return false; // odd sum → impossible
        int target = totalSum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return checkPartition(0,nums,0,target,dp);
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,5,11,5};
    cout<<s.canPartition(nums);
    return 0;
}