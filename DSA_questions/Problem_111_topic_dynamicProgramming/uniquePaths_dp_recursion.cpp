#include <iostream>
#include <vector>
using namespace std;
// 2nd method : recursion but with dp/memoisation so time complexity will change
// 2nd recursion technique : first of all : recursion where we return the value instead of using void -- 
// it would just be easy to use memoization here

// ⏱️ Time Complexity
//     Each state (i, j) is computed only once and stored in dp.
//     Total states = m * n.
//     Each state takes O(1) work (just adding two values).
//     So total time complexity = O(m * n).

// 🗂️ Space Complexity
//     Extra dp array = O(m * n).
//     Recursion depth = O(m + n).
//     So total space = O(m * n) + O(m + n).

// here dp[i][j] represents unique paths from cell i,j to destination m-1,n-1

class Solution {
public:
    int dfs(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        // either go right or go down -- no need to take care of visited right because we are always moving forward
        return dp[i][j]=dfs(i+1,j,m,n,dp)+dfs(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        // first let's go with recursive method , then dp(memo) and then dp(iterative) -- this is dp(memo) method right now
        // recursion : just means traversal right dfs mostly 
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return dfs(0,0,m,n,dp);
        
    }
};
int main() {
    Solution sol;
    int m = 3, n = 7; // Example input
    int result = sol.uniquePaths(m, n);
    std::cout << "Unique paths from (0,0) to (" << m-1 << "," << n-1 << ") is: " << result << std::endl;
    return 0;
}