#include <iostream>
#include <vector>
using namespace std;

// 1. What’s happening in your algorithm?
// For each row:
//     You try n possible columns.
//     For each valid placement, you recurse to the next row.
// This means the structure of the recursion tree looks like:
// Row 0 → n choices  
// Row 1 → up to n choices  
// Row 2 → up to n choices  
// ...
// Row n-1 → up to n choices

// If we didn’t check for safety, the total possibilities would be:
// n×n×n×...=nn
// n×n×n×...=nn
// which is O(nⁿ) — huge.

// 2. But we prune with isSafe()
// When we place a queen, we can’t use:
//     The same column again
//     The same two diagonals
// That means:
//     Row 0: n choices
//     Row 1: at most n−1 choices
//     Row 2: at most n−2 choices
//     ...
//     Row n-1: 1 choice

// So in the best case (no conflicts at all), the number of arrangements checked is:
// n×(n−1)×(n−2)×...×1=n!
// n×(n−1)×(n−2)×...×1=n!
// which is O(n!).

// 3. Cost of isSafe()
// Your isSafe() scans up to O(n) cells (column + two diagonals) each time you try a position.
// So total complexity is:
// O(n!)×O(n)=O(n⋅n!)
// O(n!)×O(n)=O(n⋅n!)
// That’s factorial time — much larger than O(n²).

// 4. Space Complexity
//     Board: vector<string> of size n × n → O(n²) space.
//     Recursion stack: depth = n → O(n).
//     Results storage: In worst case (like small n), can store multiple boards, but for complexity analysis we usually say O(n²) extra for storing one solution at a time (excluding output).
// So:
//     Auxiliary space (without counting results) = O(n²).
//     If you count all solutions in memory, it’s O(ans × n²).


class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board,int n){
        // need to check if the same col don't have the previous queen -- COL CHECK
        for(int i = 0;i<row;i++){
            if(board[i][col]=='Q') return false;
        }

        // UPPER LEFT DIAGONAL CHECK
        for(int i = row-1,j = col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }

        //UPPER RIGHT DIAGONAL CHECK
        for(int i = row-1,j = col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }

        return true;
    }
    void placeQueens(int i,int n, vector<vector<string>>& res,vector<string>& board){
        if(i == n){
            res.push_back(board);
            return;
        }
        for(int j = 0;j<n;j++){

            // check if it's safe
            if(isSafe(i,j,board,n)){
                board[i][j] = 'Q'; // place queen
                // go to the next row 
                placeQueens(i+1,n,res,board);

                board[i][j] = '.';//backtrack
            }

            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.')); // one board
        placeQueens(0,n,res,board);
        return res;
    }
};
int main() {
    Solution sol;
    int n = 4;
    vector<vector<string>> solutions = sol.solveNQueens(n);
    for (const auto& board : solutions) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}