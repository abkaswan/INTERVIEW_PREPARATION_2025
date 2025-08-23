#include <iostream>
#include <vector>
using namespace std;
// 1. ⏱️ Time Complexity
//
// With memoization, each state (i, j) is computed at most once.
// Total possible states = m * n.
// For each state, the work is O(1) (just two recursive calls and additions).
// So total time complexity = O(m * n).

// 2. 🗂️ Space Complexity
//
// - DP table: O(m * n) for storing results.
// - Recursion stack: In the worst case, you go from (0,0) to (m-1,n-1),
//   which takes (m-1 + n-1) steps = O(m+n).
//
// So total space = O(m * n) + O(m + n).

class Solution {
public:
    int dfs(int i,int j, int m, int n,vector<vector<int>>& v,vector<vector<int>>& dp){
        if(i>=m || j>=n || v[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=dfs(i+1,j,m,n,v,dp)+dfs(i,j+1,m,n,v,dp);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // method 2 : using recursion to solve this with memoization
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return dfs(0,0,m,n,obstacleGrid,dp);
    }
};
int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << "Unique Paths: " << result << endl; // Output: 2
    return 0;
}