#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSum(int i,int j,int sum,vector<int>&nums,int n){
        if(i>=n || j>=n){
            return INT_MIN;
        }
        sum+=nums[j];
        return max(sum,max(maxSum(i,j+1,sum,nums,n),maxSum(i+1,j,0,nums,n)));
    }
    int maxSubArray(vector<int>& nums) {
        // recursive method ,tc : O(2^n), sc : O(n)
        int n = nums.size();
        return maxSum(0,0,0,nums,n);
        
    }
};
int main() {
    vector<int> nums = {8,-2,-4,-1,-8,3,8,8,3,4,2,-9,-1,-3,-6,8,-3,9};
    // vector<int> nums = {-2, 1, -3, 4,-1,2,1,-5,4}; // answer should be 4 right ?
    Solution sol;
    int maxSum = sol.maxSubArray(nums);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}


// ealier version for the solution was like this : 
// class Solution {
// public:
//     void maxSum(int i,int j,int sum, int& maxi,vector<int>&nums){
//         // now there is too much that is being repeated right now so we will store it somewhere else using dp ofcourse , like dp[i][j] is being repeated 
//         if(i>=nums.size() || j>=nums.size()){
//             return;
//         }
//         sum+=nums[j];
//         maxi = max(sum,maxi);
//         maxSum(i,j+1,sum,maxi,nums);
//         maxSum(i+1,j,0,maxi,nums);
//     }
//     int maxSubArray(vector<int>& nums) {
//         // brute force : two for loops , O(n^2) time and O(1) space
//         //second method : kdnae algo , staright up dynamic programming only , last choices will affect the upcoming so first we will develop recursive approach for this 
//         // recursive method ,tc : O(2^n) , sc : O(n)
//         int maxi = INT_MIN;
//         maxSum(0,0,0,maxi,nums);
//         return maxi;
        
//     }
// };
