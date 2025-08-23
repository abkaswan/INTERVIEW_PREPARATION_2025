#include <iostream>
#include <vector>
using namespace std;
// 1. ⏱️ Time Complexity
// Each cell (i, j) is processed exactly once.
// Work per cell = O(1).
// Total cells = m * n.
// 👉 Time Complexity = O(m * n).

// 2. 🗂️ Space Complexity
// Instead of a full m x n DP table, we use a single 1D array of size n.
// 👉 Space Complexity = O(n).

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // method 4 : iterative dp optimised 
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<long long> dp(n,0); 
        // for the last row  we keep it 1 as there will be only path for those straight line , but if obstacle is there then beyong that we keep it as zero

        // bottom right cell -- for the last row last col place
        dp[n-1] = (obstacleGrid[m-1][n-1]==0);
        // fill up for last row -- for the last row calculate again
        for(int j = n-2;j>=0;j--){
            dp[j] = (obstacleGrid[m-1][j] == 1) ? 0:dp[j+1];
        }

        for(int i = m-2;i>=0;i--){
            // for the last column (not last row) we didnt handle if there is an obstacle so doing it here.
            if (obstacleGrid[i][n-1] == 1) dp[n-1] = 0;
            for(int j = n-2;j>=0;j--){
                if(obstacleGrid[i][j]==1) dp[j]=0;
                else dp[j] = dp[j]+dp[j+1];
            }    
        }
        return (int)dp[0];
    }
};
int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << "Unique Paths: " << result << endl; // Output: 2
    return 0;
}