#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n*sum) , space complexity : O(n*sum)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // method 1 : simple recursion
        // method 2 : dp with memoisation
        // method 3 : dp with iteartion
        int n = arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        // the relation will be include and exclude and then check which one is maximum
        
        // sum of 0 will always be possible by choosing empty subset
        for(int i = 0;i<=n;i++){
            dp[i][0] = true;
        }
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=sum;j++){
                // include and exclude the current element in both cases
                
                // exclude the current element arr[i-1] so it would totally depend on the previois value
                dp[i][j] = dp[i-1][j]; 
                
                // now include the current element if it is possible and check again 
                if(j>=arr[i-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
                }

            }
        }
        
        // whether sum target is possible using all n elements
        return dp[n][sum];
        
    }
};
int main() {
    Solution solution;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    if (solution.isSubsetSum(arr, sum)) {
        cout << "Found a subset with the given sum" << endl;
    } else {
        cout << "No subset with the given sum" << endl;
    }
    return 0;
}