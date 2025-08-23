#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
// time complexity : O(m*n) = first initialize and allocate dist m*n + for the two for loops it is m*n again + each cell is popped at most once (you only push a cell when you improve its distance), and for each pop you check a constant 4 neighbors. So total work ≤ 4 * (m·n) neighbor checks + m·n pops — i.e. Θ(m·n).
// space complexity : O(m*n) = we are using a queue and a distance matrix of same size as input matrix. here for the first for loop queue can be m*n in worst case
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // put all the 0s in the queue initially
        // bfs outwards to fill the distance for 1s  
        int m = mat.size(),n = mat[0].size();
       
        queue<pair<int,int>> q;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        //step 1; put all the positions where 0s are in the queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)
                 {
                    q.push({i,j});
                    dist[i][j] = 0;
                 }
            }
        }

        //step 2; using directions (all 4 directions) to navigate the neighbours 
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(auto [dx,dy]:directions){
                int nx = x+dx;
                int ny = y+dy;
                if(nx<m && ny<n && nx>=0 && ny>=0 && dist[nx][ny]>dist[x][y]+1) 
                {
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        } 
        return dist;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> result = sol.updateMatrix(mat);
    for(const auto& row : result) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}