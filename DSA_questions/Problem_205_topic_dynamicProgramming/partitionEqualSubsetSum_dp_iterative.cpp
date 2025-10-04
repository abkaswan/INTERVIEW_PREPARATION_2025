// Subset-sum style DP (bottom-up)
// State: dp[i][sum]
//   i   = index (0..n-1), means we are allowed to use elements nums[0..i]
//   sum = target sum we want to achieve
//
// Meaning: dp[i][sum] = true 
//          if we can form exactly 'sum' using a subset of the first (i+1) elements.
#include<iostream>
#include<vector>
using namespace std;
// time complexity :  O(n*sum) , space complexity : O(n*sum) and O(n) for the recursion stack

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // method 4 : iterative solution dp with iterative 
        // we need sum1 and sum2 to be equal that means sum1+sum2 = totalSum  --> 2*sum1 = totalSum;
        // sum1 = totalSum/2 so if we do it for sum1 = target then it works
        int totalSum = 0,n = nums.size();
        for(auto x : nums) totalSum+=x;
        if (totalSum % 2 != 0) return false; // odd sum → impossible
        int target = totalSum/2;
        // initially make them all false 
        vector<vector<int>> dp(n,vector<int>(target+1,0));

        // there will be base condition for the first column dp[i][0] = true always why ? because we can say that we can make subset from i to n-1 if the target = 0 , how ? by not selecting the current element 
        for(int i = 0;i<n;i++){
            dp[i][0] = 1;
        }
        // for first row -- we can say that all will be false except for the part where if including itself if it can make the required sum 
        if(nums[0]<=target) dp[0][nums[0]] = 1;        
        
        for(int i = 1;i<n;i++){
            for(int j = 1;j<=target;j++){
                // don't include the current element + include the current element
                dp[i][j] = dp[i-1][j] || (j>=nums[i]?dp[i-1][j-nums[i]]:0);
            }
        }


        return dp[n-1][target];
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,5,11,5};
    cout<<s.canPartition(nums);
    return 0;
}