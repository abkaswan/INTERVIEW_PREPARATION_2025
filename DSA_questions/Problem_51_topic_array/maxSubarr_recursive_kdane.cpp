#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // KDANE'S ALGORITHM : max subarray ending at n,  f(n) = max(value for n, value for n + f(n-1))
    // first : recursion tc : O(2^n) and sc ; O(n)
    int maxSum(vector<int>& nums,int j){
        if(j==0) return nums[0];
        return max(nums[j],nums[j]+maxSum(nums,j-1));
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int totalSum = INT_MIN;
        for(int j = 0;j<n;j++){
            // if we start from jth then frmo [0,j] == what is the maxSubarray
            totalSum = max(totalSum,maxSum(nums,j));
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