#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for std::pair

using namespace std;
// Time Complexity: O(m*n) 
//   - BFS visits each cell at most once (O(m*n)) 
//   - Restoration loop also takes O(m*n) 
//   - Overall O(m*n)
//
// Space Complexity: O(m*n) 
//   - Queue can hold up to O(m*n) in the worst case 
//   - Directions vector is O(1)

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // get all the 1s that are on the border right now
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        // for the first and last column
        for(int i = 0;i<m;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                grid[i][0] = 2;
            } 
            if(grid[i][n-1]==1){
                q.push({i,n-1});
                grid[i][n-1]=2;
            } 
        }
        // for the first and last row (excluding corners to avoid duplicates)
        for(int j = 1;j<n-1;j++){
            if(grid[0][j]==1){
                q.push({0,j});
                grid[0][j]=2;
            } 
            if(grid[m-1][j]==1){
                q.push({m-1,j});
                grid[m-1][j]=2;
            } 
        }

        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto [dx,dy]:directions){
                int nx = x+dx, ny = y+dy;
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1){
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
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
    Solution sol;
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    int result = sol.numEnclaves(grid);
    cout << "Number of Enclaves: " << result << endl; // Output: 3
    return 0;
}