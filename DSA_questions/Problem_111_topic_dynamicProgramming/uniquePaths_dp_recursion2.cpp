#include <iostream>
#include <vector>
using namespace std;

// 2nd recursion technique : first of all : recursion where we returh the value instead of using void -- it would just be easy to use memoization here
// Time Complexity
//     At each cell (i, j), you branch into two recursive calls: one going down and one going right.
//     In the worst case, you build a binary tree of calls until reaching the destination.
//     Maximum number of moves = (m-1) + (n-1) = m+n-2.
//     So the recursion depth is O(m+n).
//     Number of total calls ≈ 2^(m+n) (exponential).
// So time complexity = O(2^(m+n)), not 2^n.

// 🗂️ Space Complexity
//     You’re not using extra arrays, just recursion stack.
//     Maximum depth of recursion = (m-1)+(n-1) = m+n-2.
//     So space complexity = O(m+n).


class Solution {
public:
    int dfs(int i,int j,int m,int n){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1){
            return 1;
        }
        // either go right or go down -- no need to take care of visited right because we are always moving forward
        return dfs(i+1,j,m,n)+dfs(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        // first let's go with recursive method , then dp(memo) and then dp(iterative)
        // recursion : just means traversal right dfs mostly 
        return dfs(0,0,m,n);
        
    }
};
int main() {
    Solution sol;
    int m = 3, n = 7; // Example input
    int result = sol.uniquePaths(m, n);
    std::cout << "Unique paths from (0,0) to (" << m-1 << "," << n-1 << ") is: " << result << std::endl;
    return 0;
}