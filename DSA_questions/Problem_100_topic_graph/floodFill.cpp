#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// time complexity : O(m*n) where m is the number of rows and n is the number of columns in the image
// space complexity : O(m*n) in the worst case, where we have to store all pixels in the queue
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        // we will use BFS - as it is used for level traversal
        queue<pair<int,int>> q;
        // directions we will need for moving right, left, down, up , moving up means decreasing row by 1 
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        
        // step 1 : get to know about our stating pixel using -- sr,sc , change it's color and push it into the queue
        int colorBefore = image[sr][sc];
        // change the starting pixel and all connected pixels (up/down/left/right) that are of the same original color to the new color. so if color and colorBefore is same we can return the image directly and can prevent infinite looping in cases like : [[1,1][1,1]] , sr = 0 , sc = 0 , color = 1, now if we go through this without this condition there will be inifinite looping
        if(color == colorBefore) return image;

        q.push({sr,sc});
        image[sr][sc]=color;

        // step 2 : same type of colors change them to our colorAfter(var color here)
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto [dx,dy]:directions){
                int nx = x+dx;
                int ny = y+dy;
                // now check if image[nx][ny] is the same color as image[sr][sc] was before 
                if(nx>=0 && ny>=0 && nx<m && ny<n && image[nx][ny]==colorBefore){
                    image[nx][ny] = color;
                    q.push({nx,ny});
                }
            }
        }
        return image;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
    
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}