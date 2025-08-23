#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// time complexity : O(m*n) -- because first for loop m*n and for the queue , each cell can only be processed once when it turns from fresh to rotten , so it is pushed and poped at most once 
// space complexity : O(m*n) because of queue where all oranges could be rotten and added to queue at once in worst case right ?
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // need to check  up, left , down , right so 4-directionallly adjacent or not , for this we can't directly use 
        vector<pair<int,int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};

        // step 1 : check all the rotten oranges and push in the queue
        int freshOranges = 0;
        queue<pair<int,int>> q;
        for(int i =0 ; i<m;i++){
            for(int j = 0 ;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    freshOranges++;
            }
        }
        // step 2 : go through the queue , make the fresh oranges rotten and then push them in the queue also as they are rotten now , count minutes
        int minutes = 0;
        while(!q.empty() && freshOranges>0){
            int size = q.size();
            while(size--){
                // so at each level we can rot more oranges
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy]:directions){
                    int nx = x+dx;
                    int ny = y+dy;
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        freshOranges--;
                    }
                }
            }
            minutes++;

        }

        return freshOranges == 0 ?minutes:-1;
    }
};
int main() {
    Solution obj;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int result = obj.orangesRotting(grid);
    cout << "Minimum minutes to rot all oranges: " << result << endl; // Expected output: 4
    return 0;
}