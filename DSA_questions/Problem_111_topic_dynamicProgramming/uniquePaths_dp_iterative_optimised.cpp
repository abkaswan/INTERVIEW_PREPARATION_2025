#include <iostream>
#include <vector>
using namespace std;
// 4th method : iterative dp with space optimization

// ⏱️ Time Complexity
//     We still compute each cell once → O(m * n).

// 🗂️ Space Complexity
//     Instead of m × n dp table, we only store one row of size n.
//     So extra space = O(n).


class Solution {
public:
    int uniquePaths(int m, int n) {
        // first let's go with recursive method , then dp(memo) and then dp(iterative) -- this is dp(iterative) method right now
        
        vector<int> dp(n,1); // intializing the last row as the 1 as there is only one path for all of them straight line right ?

        // as you can see we need only two things here : the value below the current row i.e. next row, same column + value next to it i.e. next column, same row so for this we can direclty use 1D DP and use it --- if we replace the dp in place so we don't need to worry about dp[i+1][j] => dp[i] only and we are goind right to left so dp[i][j+1] => dp[i+1]
        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                dp[j] = dp[j]+dp[j+1];
            }
        }
       
        return dp[0];
    }
};
int main() {
    Solution sol;
    int m = 3, n = 7; // Example input
    int result = sol.uniquePaths(m, n);
    cout << "Unique paths from (0,0) to (" << m-1 << "," << n-1 << ") : " << result << endl;
    return 0;
}