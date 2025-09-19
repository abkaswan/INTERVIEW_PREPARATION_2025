#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time complexity : 
// At each cell (i, j) you branch into 3 possibilities (leftD, below, rightD).
// Depth of recursion = n (since you can go at most n rows down).
// So worst-case number of calls ≈ 3^n.
// And since you try from every column in the first row (n choices):
// Time = O(n · 3^n)

// Space complexity :
// Recursion stack depth = O(n) (you go down row by row).
// No extra DP table yet.
// Space = O(n).

class Solution {
public:
    int n;
    int dfs(int i,int j,vector<vector<int>>& matrix){
        if(i>=n || j<0 || j>=n) return 1e9; // out of boundary so invalid so give the max number so it doesn't choose that
        if(i==n-1) return matrix[i][j];

        int leftD = dfs(i+1,j-1,matrix); // left diagonal next row
        int below = dfs(i+1,j,matrix); // just below the current element
        int rightD = dfs(i+1,j+1,matrix); // right diagonal next row

        return matrix[i][j]+min({leftD,below,rightD});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // method 1 ; recursion 
        n = matrix.size();
        int minRes = INT_MAX;
        // send for the whole first row
        for(int j = 0;j<n;j++){
            int minNow = dfs(0,j,matrix);
            minRes = min(minRes,minNow);
        }
        return minRes;
        
        
    }
};
int main() {
    vector<vector<int>> matrix = {
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };
    Solution sol;
    int result = sol.minFallingPathSum(matrix);
    cout << "The minimum falling path sum is: " << result << endl;
    return 0;
}