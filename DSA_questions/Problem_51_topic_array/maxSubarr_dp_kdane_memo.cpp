#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // KDANE'S ALGORITHM : max subarray ending at n,  f(n) = max(value for n, value for n + f(n-1))
    // first : recursion tc : O(2^n) and sc ; O(n)
    // memoization dp , tc : O(n) and sc : O(n)+O(n) for dp and recursion stack
    
    // dp[i] here represents that for the subarray (0,i) what is the maximum sum 
    int maxSum(vector<int>& nums,int j,vector<int>& dp){
        if(j==0) return nums[0];
        if(dp[j]!=INT_MIN) return dp[j];
        return dp[j]=max(nums[j],nums[j]+maxSum(nums,j-1,dp));
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int totalSum = INT_MIN;
        vector<int> dp(n,INT_MIN);// because 0 to n-1
        for(int j = 0;j<n;j++){
            // if we start from jth then frmo [j,n-1] == what is the maxSubarray
            totalSum = max(totalSum,maxSum(nums,j,dp));
        }
        return totalSum;        
    }
};
int main() {
    // vector<int> nums = {8,-2,-4,-1,-8,3,8,8,3,4,2,-9,-1,-3,-6,8,-3,9}; //28
    vector<int> nums = {-2, 1, -3, 4,-1,2,1,-5,4}; // answer should be 6 right ?
    Solution sol;
    int maxSum = sol.maxSubArray(nums);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}