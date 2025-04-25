#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        //create one dp for this. dp[i][j]
        // here i - how many elements from the array you are considering from 0 to n-1
        //  j - every possible sum from 0 to k.
        int n = nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        // dp[0][0]=1; //initiliaze it with 1 because there is one way to make sum 0 if we don't include any elements
        // if you do it with space complexity : O(n*k)
        // for(int i = 1;i<=n;i++)
        // {
        //     for(int j=0;j<=k;j++)
        //     {
        //         //write the dp relation which is either we exclude it : in this case possibility of subsequences is same as dp[i-1][j]
        //         // either we include it : then we need to find j-nums[i] possiblity for the remaining items so dp[i-1][j-nums[i]]
        //         dp[i][j]=dp[i-1][j]+(j-nums[i-1]>=0?dp[i-1][j-nums[i-1]]:0); //here we are using nums[i-1] for current element because if we use i which is one indexed it won't work 
        //     }
        // }

        // but you can do it in : O(k) only  -- 
        vector<int> dp(k+1,0);
        dp[0]=1; // how many ways when there is not element
        // not we go through each element
        for(int i = 1;i<=n;i++)
        {
            // Here use top down apparoch so that we dp[i-1][j] which we do when we need to include will always be there 
            // And when we include dp[i-1][s-nums[i-1]] only we will need to do 
            int x = nums[i-1];
            for(int j=k;j>=x;j--)  // only need to go till k-nums[i-1]>=0 or j>=nums[i-1] only before that the values won't be changing only right ? above it was 2d array so we needed it do it to update dp[i-1][j] values but here we don't need to 
            {
                dp[j]+=dp[j-x];
            }
        }
        return dp[k];
    }
};

int main() {
    vector<int> nums = { 4, 9, 2, 5, 1 };
    int k = 10; // your target sum here

    Solution sol;
    int result = sol.countSubsequenceWithTargetSum(nums, k);

    cout << "Result: " << result << endl;

    return 0;
}
