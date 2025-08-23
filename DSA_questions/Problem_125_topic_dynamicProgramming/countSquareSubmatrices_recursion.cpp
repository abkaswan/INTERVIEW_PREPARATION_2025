#include <iostream>
#include <vector>
using namespace std;

// Time & Space Complexity Analysis
// --------------------------------

// 1) What each recursive call does:
//    - For cell (i,j), the function calls:
//        countRecursive(i-1, j),
//        countRecursive(i,   j-1),
//        countRecursive(i-1, j-1).
//    - So each call branches into 3 more calls until hitting boundaries.
//    - Let T(i,j) = cost of computing countRecursive(i,j).
//      Then:
//          T(i,j) = T(i-1,j) + T(i,j-1) + T(i-1,j-1) + O(1).

// 2) Bounding the recursion:
//    - Define d = i + j (distance from origin).
//    - Each call reduces d by 1 (moving up, left, or diagonal).
//    - So recursion depth ≤ i+j.
//    - Each node in the recursion tree can spawn up to 3 children.
//    - Upper bound on calls = 1 + 3 + 3^2 + ... + 3^d = O(3^d).
//    - Therefore: T(i,j) = O(3^(i+j)).

// 3) Total work for all cells:
//    - We call countRecursive(i,j) for every (i,j).
//    - Total = Σ Σ T(i,j) over all i,j.
//    - Substitute bound: Σ Σ O(3^(i+j)).
//    - Factor into two geometric sums:
//        (Σ from i=0..n-1 of 3^i) * (Σ from j=0..m-1 of 3^j).
//    - Each sum = (3^n - 1)/2 and (3^m - 1)/2.
//    - Multiply → O(3^(n+m)).
//    - So the total complexity is Θ(3^(n+m)).
//    - Important: it is not O(n*m*3^(n+m)); the geometric sum collapses
//      to ~3^(n+m) without the extra polynomial factor.

// 4) Space complexity:
//    - Maximum recursion depth = i+j.
//    - For bottom-right cell, depth = (n-1)+(m-1) = O(n+m).
//    - No extra data structures are used.
//    - So space complexity = O(n+m).

// 5) Final Answer:
//    - Time (worst-case, all ones, no memoization): Θ(3^(n+m))
//    - Space (recursion stack): O(n+m)

// explaining the definition of d:
// i=2,j=2. Define  d=i+j=4
// This means at most 4 recursive steps before one of the indices becomes negative.
// (e.g., path: (2,2) → (1,2) → (0,2) → (-1,2) stops, so depth ≤ 4.

class Solution {
public:
    // i is row, j is column
    int countRecursive(int i,int j,vector<vector<int>>& matrix){
        if(i<0 || j<0) return 0;
        
        if(matrix[i][j]==0) return 0;
        return 1+min({countRecursive(i-1,j,matrix),countRecursive(i,j-1,matrix),countRecursive(i-1,j-1,matrix)});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = 0;
        
        // Call recursion for every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                total += countRecursive(i, j, matrix);
            }
        }
        return total;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    int result = sol.countSquares(matrix);
    cout << "Total square submatrices: " << result << endl; // Output: 7
    return 0;
}