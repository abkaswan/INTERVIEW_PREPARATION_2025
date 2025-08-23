#include <iostream>
#include <vector>
using namespace std;
// Time Complexity : O(m^2) where m is the number of rows in the triangle : (each (i, j) computed once, total ~ m(m+1)/2 states).
// Space Complexity : O(m^2) for the dp table, where m is the number of rows in the triangle + O(m) for the recursion stack

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        // method 3 : try dp bottom up now , go to i+1,j or i+1,j+1 right ?
        vector<vector<int>> dp(m);
        
        for (int i = 0; i < m; i++) {
            dp[i].assign(i+1, 0);
        }

        // now for the last row itself is the answer right ?
        for(int j = 0;j<m;j++){
            dp[m-1][j]=triangle[m-1][j];
        }

        for(int i = m-2;i>=0;i--){
            for(int j = 0;j<=i;j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
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