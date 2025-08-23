#include <iostream>
#include <vector>
using namespace std;
// 1.  ⏱️ Time Complexity

// At each cell (i, j), you branch into two recursive calls:
// One goes down (i+1, j)
// One goes right (i, j+1)

// So in the worst case (no obstacles):
// The recursion tree behaves like a binary tree of height (m-1 + n-1) = m+n-2.
// Number of recursive calls ≈ 2^(m+n) (exponential).
// 👉 Yes, time complexity = O(2^(m+n)) in the worst case.

// 2. 🗂️ Space Complexity
// Space comes from the recursion stack depth:
// The longest path from (0,0) to (m-1, n-1) takes exactly (m-1) downs + (n-1) rights.
// That’s a recursion depth of (m-1 + n-1) = m+n-2.
// So Space complexity = O(m+n).

class Solution {
public:
    int dfs(int i,int j, int m, int n,vector<vector<int>>& v){
        if(i>=m || j>=n || v[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;

        return dfs(i+1,j,m,n,v)+dfs(i,j+1,m,n,v);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // method 1 : using recursion to solve this , might need backtracking or something keep in mind
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return dfs(0,0,m,n,obstacleGrid);
    }
};
int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << "Unique Paths: " << result << endl; // Output: 2
    return 0;
}