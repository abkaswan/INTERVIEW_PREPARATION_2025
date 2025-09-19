#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n*sum) , space complexity : O(n*sum)
// the only difference from method 1 is we are taking n instead of n+1 so the intialization and all was changed slightly
class Solution {
  public:
    //   dp[i][j] means: "Is it possible to form the sum j using the first i elements of the arr array?
    bool isSubsetSum(vector<int>& arr, int sum) {
        // method 1 : simple recursion
        // method 2 : dp with memoisation
        // method 3 : dp with iteartion
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        // the relation will be include and exclude and then check which one is maximum
        
        // sum of 0 will always be possible by choosing empty subset
        dp[0][0] = true; // with arr[0] we can for the sum by not taking hte arr[0]
        // and form sum arr[0] , by taking arr[0]
        // if(arr[0]<=sum){
            dp[0][arr[0]]=true;
        // }
        
        for(int i = 1;i<n;i++){
            for(int j = 0;j<=sum;j++){
                // include and exclude the current element in both cases
                
                // exclude the current element arr[i-1] so it would totally depend on the previois value
                dp[i][j] = dp[i-1][j]; 
                
                // now include the current element if it is possible and check again 
                if(j>=arr[i]){
                    dp[i][j] = dp[i][j] || dp[i-1][j-arr[i]];
                }

            }
        }
        
        // whether sum target is possible using all n elements
        return dp[n-1][sum];
        
    }
};
int main() {
    Solution sol;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    if (sol.isSubsetSum(arr, sum))
        cout << "Found a subset with given sum" << endl;
    else
        cout << "No subset with given sum" << endl;
    return 0;
}