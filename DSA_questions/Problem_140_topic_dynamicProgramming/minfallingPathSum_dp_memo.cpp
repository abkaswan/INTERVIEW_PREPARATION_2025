#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Time Complexity : O(n^2) - each cell (i,j) is computed once
// Space Complexity : O(n^2) for dp table + O(n) for recursion stack
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int dfs(int i,int j,vector<vector<int>>& matrix){
        if(i>=n || j<0 || j>=n) return 1e9; // out of boundary so invalid so give the max number so it doesn't choose that
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int leftD = dfs(i+1,j-1,matrix); // left diagonal next row
        int below = dfs(i+1,j,matrix); // just below the current element
        int rightD = dfs(i+1,j+1,matrix); // right diagonal next row

        return dp[i][j]=matrix[i][j]+min({leftD,below,rightD});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // method 2 ; recursion with memoization
        n = matrix.size();
        int minRes = INT_MAX;
        dp.assign(n,vector<int>(n,-1));
        // send for the whole first row
        for(int j = 0;j<n;j++){
            int minNow = dfs(0,j,matrix);
            minRes = min(minRes,minNow);
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