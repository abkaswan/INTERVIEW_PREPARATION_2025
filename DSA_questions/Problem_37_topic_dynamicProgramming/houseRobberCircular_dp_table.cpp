#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // dp[i] stores the maximum amount that can be robbed from houses [start...i]
    // time complexity : O(n) overall = >O(2n){for building the arrays}+O(2n){each position is calcualted only once , twice for subStart and subEnd}
    // space complexity : O(n) overall => O(2n){for extra arrays}+O(n){for dp arrays , here we resuse the same array} 
    int robSum(vector<int>& nums,vector<int>& dp){
        int n = nums.size();
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        // method 1 : recursion
        // methdo 2: dp memoization -- recursive
        // method 3 : dp tabulation -- iteartive
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        vector<int> dp(n,-1);
        vector<int> nums1,nums2;
        for(int i = 0;i<n;i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
        }
        int subStart = robSum(nums1,dp);
        dp = vector<int>(n,-1);
        int subEnd = robSum(nums2,dp);
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
