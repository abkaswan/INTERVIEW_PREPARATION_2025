#include <iostream>
#include <vector>
using namespace std;
// 1. ⏱️ Time Complexity
// Each cell (i, j) is computed exactly once.
// Work per cell = O(1) (just checking obstacle and adding two values).
// Total cells = m * n.
// 👉 Time Complexity = O(m * n).

// 2. 🗂️ Space Complexity
// We are using a dp table of size m x n.
// 👉 Space Complexity = O(m * n).
// (Can be optimized to O(n) using a single row, since each cell depends only on right and down.)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // method 3 : iterative dp 
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n,0)); 
        // for the last row and column we keep it 1 as there will be only path for those straight line , but if obstacle is there then beyong that we keep it as zero

        // bottom right cell 
        dp[m-1][n-1] = (obstacleGrid[m-1][n-1]==0);
        // fill up for last row 
        for(int j = n-2;j>=0;j--){
            dp[m-1][j] = (obstacleGrid[m-1][j] == 1) ? 0:dp[m-1][j+1];
        }
        // fill up for last column 
        for(int i = m-2;i>=0;i--){
            dp[i][n-1] = (obstacleGrid[i][n-1] == 1) ? 0:dp[i+1][n-1];   
        }

        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }    
        }
        return (int)dp[0][0];
    }
};
int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << "Unique Paths: " << result << endl; // Output: 2
    return 0;
}