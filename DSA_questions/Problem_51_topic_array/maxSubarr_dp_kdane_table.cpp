#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // KDANE'S ALGORITHM : max subarray ending at n,  f(n) = max(value for n, value for n + f(n-1))
    // first : recursion tc : O(2^n) and sc ; O(n)
    // second : memoization dp , tc : O(n) and sc : O(n)+O(n) for dp and recursion stack
    // third : table format, tc : O(n) and sc : O(n) for dp
    // dp[i] here represents that for the subarray (0,i) what is the maximum sum 
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int totalSum = INT_MIN;
        vector<int> dp(n,INT_MIN); // because 0 to n-1
        dp[0]=nums[0];
        totalSum = max(totalSum,dp[0]);

        for(int i = 1;i<n;i++){
            // if we start from jth then frmo [j,n-1] == what is the maxSubarray
            dp[i] = max(nums[i],nums[i]+dp[i-1]);
            totalSum = max(totalSum,dp[i]);
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