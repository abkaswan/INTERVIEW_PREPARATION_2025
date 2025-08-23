#include <iostream>
#include <vector>
using namespace std;

// 3rd method : doing iterative dp so no need to do recursion here

// ⏱️ Time Complexity
//     We fill an m × n table.
//     Each cell (i, j) is computed exactly once.
//     Each computation takes O(1) time.
//     So total time complexity = O(m * n).

// 🗂️ Space Complexity
//     We use an m × n dp array.
//     So extra space = O(m * n).
//     (Can be optimized to O(n) if we only keep one row at a time).

// here dp[i][j] represents unique paths from cell (i, j) to destination (m-1, n-1)

class Solution {
public:
    int uniquePaths(int m, int n) {
        // first let's go with recursive method , then dp(memo) and then dp(iterative) -- this is dp(iterative) method right now
        
        vector<vector<int>> dp(m,vector<int>(n,1)); // because for the last row or column there is only one path either go straight down or right so intialized it with 1

        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
       
        return dp[0][0];
    }
};
int main() {
    Solution sol;
    int m = 3, n = 7; // Example input
    int result = sol.uniquePaths(m, n);
    cout << "Unique paths from (0,0) to (" << m-1 << "," << n-1 << ") : " << result << endl;
    return 0;
}