#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Time Complexity : O(n^2) - each cell (i,j) is computed once
// Space Complexity : O(n^2) for dp table
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // method 3 ; dynamic programming with iterative bottom up method
        int n = matrix.size();
        vector<vector<int>> dp = matrix; // so that last row gets filled by itself and other we will overwrite them 
        
        // for the first and last columns also we need to do it right -- so we are doing outside the for loop 
        for(int i = n-2;i>=0;i--){
            dp[i][0] = matrix[i][0]+min(dp[i+1][0],dp[i+1][1]);
            dp[i][n-1] = matrix[i][n-1]+min(dp[i+1][n-2],dp[i+1][n-1]);
            
            for(int j = 1;j<n-1;j++){
                dp[i][j]=matrix[i][j]+min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
            }
        }
        
        int minRes = INT_MAX;
        for(int j = 0;j<n;j++){
            minRes = min(dp[0][j],minRes);
        }
        return minRes;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    int result = sol.minFallingPathSum(matrix);
    cout << "Minimum falling path sum: " << result << endl;
    return 0;
}