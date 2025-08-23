#include <iostream>
#include <vector>

using namespace std;

// Time Complexity :
// From each cell (i, j) you have 2 choices: go right or go down.
// In the worst case, you’ll explore almost all paths from (0,0) to (m-1,n-1).
// Number of such paths ≈ binomial coefficient C(m+n-2, m-1) (all ways of arranging rights and downs).
// That grows asymptotically like O(2^(m+n)) if you expand the recursion tree (since every step branches into 2).
// So yes, without memoization,
// Time Complexity = O(2^(m+n))

// 🗂 Space Complexity : O(m+n)
// You’re only using recursion stack, no extra storage.
// In the worst case, you’ll go down + right until bottom-right, so recursion depth = (m-1 + n-1) = m+n-2.
// That is O(m+n).

class Solution {
public:
    int n,m;
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i>=m || j>=n) return 1e9; // since going out is invalid
        if(i==m-1 && j==n-1){
            return grid[i][j]; // reached end
        }
        return grid[i][j]+min(dfs(i+1,j,grid),dfs(i,j+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        // so either go right or down 
        // method 1 : do it using recursion 
        m = grid.size();
        n = grid[0].size();

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