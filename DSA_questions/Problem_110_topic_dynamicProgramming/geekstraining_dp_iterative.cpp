#include <iostream>
#include <vector>
using namespace std;

// Time complexity : O(n) 
// Space complexity :
//     no recursive stack for this method and you use O(4*n) extra space for vector

// iterative -- bottom up approach
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        if(arr.empty()) return 0;
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(4, 0)); // dp[n][*] = 0
        // dp[i][prev] = max sum from row i if previous column chosen is prev (0..2), 3 => no previous
        for(int i = n-1;i>=0;i--){
            for(int prev=0;prev<=3;prev++){
                int best = 0;
                for(int j = 0;j<3;j++){
                    if(prev==j) continue;
                    int val = arr[i][j]+dp[i+1][j];
                    best = max(best,val);    
                }
                dp[i][prev] = best;
            }
        }
        return dp[0][3]; // we are returninig this and not dp[0][0] etc because if we return dp[0][0] that means it assumed that prev was 0 in that case in the for loop for j it would have taken best for j = 1 & j = 2 only and left others so either return this or return max(dp[0][0],dp[0][1],dp[0][2])
        // return max(dp[0][0],max(dp[0][1],dp[0][2]));
        
    }
};
int main() {
    Solution sol;
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int result = sol.maximumPoints(arr);
    cout << "Maximum Points: " << result << endl;
    return 0;
}