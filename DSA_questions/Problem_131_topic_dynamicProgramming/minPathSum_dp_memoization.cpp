#include <iostream>
#include <vector>
using namespace std;
// Time Complexity : O(m*n) - each cell (i,j) is computed once
// Space Complexity : O(m*n) for dp table + O(m+n) for recursion stack

// here dp[i][j] is :  The minimum path sum starting at cell (i, j) and ending at the bottom-right cell (m-1, n-1)
class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i>=m || j>=n) return 1e9; // since going out is invalid
        if(i==m-1 && j==n-1){
            return grid[i][j]; // reached end
        }
        // memoization
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=grid[i][j]+min(dfs(i+1,j,grid),dfs(i,j+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        // so either go right or down 
        // method 1 : do it using recursion 
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<int>(n, -1)); // initialize memo table

        return dfs(0,0,grid);
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int result = sol.minPathSum(grid);
    
    cout << "Minimum path sum: " << result << endl;
    
    return 0;
}