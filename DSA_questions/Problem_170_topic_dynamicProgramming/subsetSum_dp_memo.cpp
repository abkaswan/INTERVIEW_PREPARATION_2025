#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n*sum) , space complexity : O(n*sum) + O(n) for recursion stack
class Solution {
  public:
    bool allsubsets(int i, vector<int>& arr, int target,int sum,vector<vector<int>>& dp){
      if(sum==target){
        return true;
      }
      if(i>=arr.size() || sum>target){ //break it or return it not possible
        return false;
      }
        
      if(dp[i][sum]!=-1){
          return dp[i][sum]==1;
      }
      // include the current arr[i] for the sum 
      // exclude the current arr[i] for the sum 
      return dp[i][sum] = allsubsets(i+1,arr,target,sum+arr[i],dp) || allsubsets(i+1,arr,target,sum,dp);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // method 1 : simple recursion
        // method 2 : dp with memoisation
        vector<vector<int>> dp(arr.size(),vector<int>(sum,-1));
        return allsubsets(0,arr,sum,0,dp);
        
    }
};
int main() {
    Solution sol;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    if (sol.isSubsetSum(arr, sum))
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}