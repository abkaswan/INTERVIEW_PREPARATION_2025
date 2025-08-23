#include <iostream>
#include <vector>
using namespace std;

// Time Complexity : O(m^2) where m is the number of rows in the triangle : (each (i, j) computed once, total ~ m(m+1)/2 states).
// Space Complexity : O(m) for the dp array, where m is the number of rows in the triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        // method 4 : try dp bottom up now -- but optimised, go to i+1,j or i+1,j+1 right ?
        vector<int> dp(m,0);

        // now for the last row itself is the answer right ?
        for(int j = 0;j<m;j++){
            dp[j]=triangle[m-1][j];
        }

        for(int i = m-2;i>=0;i--){
            // there is no last column we need to satisfy here so no need to do anything here 
            for(int j = 0;j<=i;j++){
                dp[j] = triangle[i][j]+min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
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