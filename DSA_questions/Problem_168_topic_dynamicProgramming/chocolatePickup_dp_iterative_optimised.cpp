#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// time complexity : O(9*n*m*m) and space complexity : O(m*m)
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // method 4 ; recursion with iterative optimised
        vector<vector<int>> dp(m,vector<int>(m,0));
        // step 1 : fill the last row first
        for(int j1 = 0;j1<m;j1++){
            for(int j2 = 0;j2<m;j2++){
                if(j1==j2) dp[j1][j2]=grid[n-1][j1];
                else dp[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        // step 2 : now work on other rows 
        for(int i = n-2;i>=0;i--){
            vector<vector<int>> curr(m,vector<int>(m,0));
            for(int j1 = 0;j1<m;j1++){
                for(int j2 = 0;j2<m;j2++){
                    int val = 0;
                    if(j1==j2) val = grid[i][j1];
                    else val=grid[i][j1]+grid[i][j2];
                    
                    int panty = -1e9;
                            
                    for(int dj1 = -1;dj1<2;dj1++){
                        for(int dj2 = -1;dj2<2;dj2++){
                            int newj1 = j1+dj1,newj2 = j2+dj2;
                            if(newj1<m && newj2<m && newj1>=0 && newj2>=0){
                                panty = max(panty,dp[newj1][newj2]);    
                            }
                            
                        }
                    }
                    
                    curr[j1][j2] = panty+val;
                    
                }
            }
            
            dp = curr;
        }
        return dp[0][m-1];
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