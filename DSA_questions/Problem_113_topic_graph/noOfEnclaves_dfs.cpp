#include <iostream>
#include <vector>
using namespace std;
// Time Complexity: O(m * n)
//   - We perform DFS from each border cell at most once.
//   - Each cell is visited and marked only once across all DFS calls.
//   - Then we scan the entire grid once more to count and restore.
//   Therefore: O(m * n) for traversal + O(m * n) for final scan = O(m * n).

// Space Complexity: O(m * n) in the worst case
//   - The recursion stack can go as deep as m * n in a worst-case scenario (e.g., one long path).
//   - We modify the grid in place, so no additional data structure of size O(m * n) is used.
//   - Thus overall auxiliary space = O(1) for the grid itself + O(m * n) for recursion stack.

class Solution {
public:
    void dfs(int i , int j , vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!=1) return;
        grid[i][j] = 2; //make them 2
        
        // go for all four directions
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);

    }
    int numEnclaves(vector<vector<int>>& grid) {
        // get all the 1s that are on the border right now
        int m = grid.size();
        int n = grid[0].size();
        
        // doing dfs implementation
        // for the first and last column
        for(int i = 0;i<m;i++){
            dfs(i,0,grid);
            dfs(i,n-1,grid);

        }
        // for the first and last row (excluding corners to avoid duplicates)
        for(int j = 1;j<n-1;j++){
            dfs(0,j,grid);
            dfs(m-1,j,grid);
        }

        // now count how many 1s are there that is your answer ? and convert back the 2s to 1s again
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) count++;
                else if(grid[i][j]==2) grid[i][j]=1;  // restore
            }
        }
        return count;
        
    }
};
int main() {
    // Example usage
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    int result = sol.numEnclaves(grid);
    cout << "Number of enclaves: " << result << endl; // Output: 3
    return 0;
}