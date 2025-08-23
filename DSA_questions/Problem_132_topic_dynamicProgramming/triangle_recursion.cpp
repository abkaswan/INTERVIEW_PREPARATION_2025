#include <iostream>
#include <vector>
using namespace std;

// Time Complexity :
// At each cell (i, j), you make two recursive calls:
// → one to (i+1, j) and one to (i+1, j+1)
// The recursion tree can branch like a binary tree.
// In the worst case (height m), you explore ~2^m paths.
// Time Complexity = O(2^m)
// (where m = number of rows in the triangle).
//
// 🗂 Space Complexity : O(m)
// No extra DP table, only recursion stack.
// Maximum recursion depth = m (from row 0 to row m-1).

class Solution {
public:
    int m,n;
    int dfs(int i, int j, vector<vector<int>>& triangle){
        // each row i has exactly i+1 elements, so j >= n is not the right check. use j>i instead
        if(i>=m || j>i) return 1e9; // as invalid path

        if(i==m-1) return triangle[i][j];

        return triangle[i][j]+min(dfs(i+1,j,triangle),dfs(i+1,j+1,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        m = triangle.size();
        n = triangle[0].size();

        // method 1 : try recursion first , go to i+1,j or i+1,j+1 right ?

        return dfs(0,0,triangle);
    }
};
int main() {
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    
    int result = sol.minimumTotal(triangle);
    cout << "Minimum path sum: " << result << endl; // Output: 11
    
    return 0;
}