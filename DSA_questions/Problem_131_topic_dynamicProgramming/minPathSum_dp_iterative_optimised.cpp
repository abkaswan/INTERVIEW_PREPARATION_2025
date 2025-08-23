#include <iostream>
#include <vector>
using namespace std;
// Time Complexity : O(m*n) - each cell (i,j) is computed once
// Space Complexity : O(n) for dp table -- optimised space, we only need one row at a time
class Solution {
public:
    int n,m;    
    int minPathSum(vector<vector<int>>& grid) {
        // so either go right or down 
        // method 4: do it using iterative bottom up dp -- optimised space O(n) only 
        m = grid.size();
        n = grid[0].size();
        
        vector<int> dp(n,0);

        dp[n-1] = grid[m-1][n-1]; // for the last m-1,n-1 cell
        
        // do for last row
        for(int j = n-2;j>=0;j--){
            dp[j] = grid[m-1][j]+dp[j+1];
        }
        // do for the rest of them 
        for(int i = m-2;i>=0;i--){
            // handle last column , here we can only go down not forward
            dp[n-1] = grid[i][n-1]+dp[n-1];
            for(int j = n-2;j>=0;j--){
                dp[j] = grid[i][j]+min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int result = sol.minPathSum(grid);
    
    cout << "Minimum path sum: " << result << endl;
    
    return 0;
}