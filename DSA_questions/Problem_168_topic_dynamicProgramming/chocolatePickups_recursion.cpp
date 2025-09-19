#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity : O(9^n) , space complexity : O(n)
// reason : at every step we are making 9 calls and the depth of the recursion tree is n
class Solution {
  public:
    int solveIt(int i,int j1, int j2, vector<vector<int>>& grid,int n, int m){
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9; // invalid column
        
        if(i==n-1) //reached the last row
        {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        
        // chocolate collected on this row
        int count;
        if(j1==j2) count = grid[i][j1];
        else count = grid[i][j1]+grid[i][j2];
        
        // total 9 combinations -- so get the max from those state
        int maxi = -1e9;
        for(int dj1 = -1;dj1<2;dj1++){
            for(int dj2 = -1;dj2<2;dj2++){
                maxi = max(maxi,solveIt(i+1,j1+dj1,j2+dj2,grid,n,m));
            }
        }
        
        // return the answer
        return count+maxi;
        
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // method 1 : simple recursion
        
        // it will start from 0,0 and 0,m-1
        return solveIt(0,0,m-1,grid,n,m);
        
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = grid.size();
    int m = grid[0].size();
    cout << "Maximum chocolates collected: " << sol.solve(n, m, grid) << endl;
    return 0;
}