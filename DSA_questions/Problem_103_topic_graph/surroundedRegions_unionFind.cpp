#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
    }
};
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    sol.solve(board);
    
    // Print the modified board
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    return 0;
}