// Subset-sum style DP (bottom-up, 1D optimized)
// State: dp[sum]
// sum = target sum we want to achieve
//
// Meaning: dp[sum] = true 
//          if we can form exactly 'sum' using a subset of the elements seen so far
//          (i.e., considering nums[0..current_index] while iterating through the array).
//
// Note: We iterate sum from target → nums[i] to avoid overwriting values we still need.
#include<iostream>
#include<vector>
using namespace std;
// time complexity :  O(n*sum) , space complexity : O(sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // method 5 : iterative solution dp -- 1d array
        // we need sum1 and sum2 to be equal that means sum1+sum2 = totalSum  --> 2*sum1 = totalSum;
        // sum1 = totalSum/2 so if we do it for sum1 = target then it works
        int totalSum = 0,n = nums.size();
        for(auto x : nums) totalSum+=x;
        if (totalSum % 2 != 0) return false; // odd sum → impossible
        int target = totalSum/2;
        // initially make them all false
        vector<int> dp(target+1,0);
        // for the target = 0 it will considered true alwauys
        dp[0] = 1;

        for(int i = 0;i<n;i++){
            for(int j = target;j>=nums[i];j--){
                // don't include the current element + include the current element
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }


        return dp[target];
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,5,11,5};
    cout<<sol.canPartition(nums)<<endl; // Output: true
    return 0;
}