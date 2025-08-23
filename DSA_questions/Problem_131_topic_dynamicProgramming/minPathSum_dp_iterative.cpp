#include <iostream>
#include <vector>
using namespace std;
// Time Complexity : O(m*n) - each cell (i,j) is computed once
// Space Complexity : O(m*n) for dp table -- can be optimised to O(n) if we keep only one row
class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    
    int minPathSum(vector<vector<int>>& grid) {
        // so either go right or down 
        // method 3: do it using iterative bottom up dp
        m = grid.size();
        n = grid[0].size();
        
        dp.assign(m+1, vector<int>(n+1, 0)); // initialize memo table

        dp[m-1][n-1] = grid[m-1][n-1];
        
        // now do for last col
        for(int i = m-2;i>=0;i--){
            dp[i][n-1]=grid[i][n-1]+dp[i+1][n-1];
        }
        // do for last row
        for(int j = n-2;j>=0;j--){
            dp[m-1][j]=grid[m-1][j]+dp[m-1][j+1];
        }
        // do for the rest of them 
        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int result = sol.minPathSum(grid);
    
    cout << "Minimum path sum: " << result << endl;
    
    return 0;
}