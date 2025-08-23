#include <iostream>
#include <vector>
using namespace std;
// Time Complexity : O(m^2) where m is the number of rows in the triangle : (each (i, j) computed once, total ~ m(m+1)/2 states).
// Space Complexity : O(m^2) for the dp table, where m is the number of rows in the triangle + O(m) for the recursion stack

// the minimum path sum starting from cell (i,j) to the bottom of the triangle.
class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int dfs(int i, int j, vector<vector<int>>& triangle){
        // each row i has exactly i+1 elements, so j >= n is not the right check. use j>i instead
        if(i>=m || j<0 || j>i) return INT_MAX/2; // as invalid path
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i==m-1) return triangle[i][j];
        
        return dp[i][j]=triangle[i][j]+min(dfs(i+1,j,triangle),dfs(i+1,j+1,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        m = triangle.size();
        n = triangle[0].size();

        // method 2 : try memoization now , go to i+1,j or i+1,j+1 right ?
        dp.resize(m);
        for (int i = 0; i < m; i++) {
            dp[i].assign(i+1, -1);
        }

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