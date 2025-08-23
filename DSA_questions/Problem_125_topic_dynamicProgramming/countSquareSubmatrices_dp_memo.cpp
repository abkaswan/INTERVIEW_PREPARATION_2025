#include <iostream>
#include <vector>
using namespace std;

// it would have been the same as recursion but With memoization:
//    - Each (i,j) result is computed once.
//    - Time = O(n*m)
//    - Space = O(n*m) for dp + O(n+m) recursion stack

class Solution {
public:
    // i is row, j is column
    vector<vector<int>> dp;
    int countRecursive(int i,int j,vector<vector<int>>& matrix){
        if(i<0 || j<0) return 0;
        
        // memoization : 
        if(dp[i][j]!=-1) return dp[i][j];


        if(matrix[i][j]==0) return 0;
        return dp[i][j] = 1+min({countRecursive(i-1,j,matrix),countRecursive(i,j-1,matrix),countRecursive(i-1,j-1,matrix)});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = 0;
        dp.assign(n, vector<int>(m, -1)); // initialize memo table
        
        // Call recursion for every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                total += countRecursive(i, j, matrix);
            }
        }
        return total;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    int result = sol.countSquares(matrix);
    cout << "Total square submatrices: " << result << endl; // Output: 7
    return 0;
}