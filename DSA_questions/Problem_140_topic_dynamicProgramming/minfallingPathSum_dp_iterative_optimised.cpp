#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Time Complexity : O(n^2) - each cell (i,j) is computed once
// Space Complexity : O(n) for outerDp vector + O(n) for dp vector in each iteration
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // method 4 ; dynamic programming with iterative bottom up method -- space efficient
        int n = matrix.size();
        vector<int> outerDp = matrix[n-1]; 
        
        // for the first and last columns also we need to do it right -- so we are doing outside the for loop 
        for(int i = n-2;i>=0;i--){
            vector<int> dp(n);
            dp[0] = matrix[i][0]+min(outerDp[0],outerDp[1]);
            dp[n-1] = matrix[i][n-1]+min(outerDp[n-2],outerDp[n-1]);
            
            for(int j = 1;j<n-1;j++){
                dp[j]=matrix[i][j]+min({outerDp[j-1],outerDp[j],outerDp[j+1]});
            }

            outerDp = dp; // move one row at a time
        }
        
        int minRes = INT_MAX;
        for(int j = 0;j<n;j++){
            minRes = min(outerDp[j],minRes);
        }
        return minRes;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    int result = sol.minFallingPathSum(matrix);
    cout << "Minimum falling path sum: " << result << endl;
    return 0;
}



// can write it like this also : 
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<int> next = matrix[n-1];  // start from last row

//         for (int i = n-2; i >= 0; i--) {
//             vector<int> curr(n);
//             for (int j = 0; j < n; j++) {
//                 int best = next[j]; // below
//                 if (j > 0) best = min(best, next[j-1]); // left diagonal
//                 if (j < n-1) best = min(best, next[j+1]); // right diagonal
//                 curr[j] = matrix[i][j] + best;
//             }
//             next = curr; // move up one row
//         }

//         return *min_element(next.begin(), next.end()); // answer is min of top row
//     }
// };
