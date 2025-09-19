#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Time Complexity: O(1) (since grid is fixed at 9×9, otherwise O(N²)).
// Space Complexity: O(1) (since only 27 sets of max size 9, otherwise O(N²)).
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // make sets for row , column and 3*3 boxes -- total 9 for each of them
        vector<unordered_set<int>> srow(9),scol(9),sbox(9);
        // srow[i] - stores numbers in i-th row , scol[i] - store numbers in j-th row , sbox[i/3*3+j/3] -- stores numbers in 3*3 sub-box
        // add the rows first , cols second and at last boxes
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){

                int num = board[i][j];
                // here you can do board[i][j]-'0' also to properly save otherwise it is saving number as 56 , 57 and all according to ASCII values 
                if(num=='.') continue;
                
                if(srow[i].count(num)) return false;
                srow[i].insert(num);

                if(scol[j].count(num)) return false;
                scol[j].insert(num);

                int index = (i/3)*3+(j/3);
                if(sbox[index].count(num)) return false;
                sbox[index].insert(num);
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    bool result = sol.isValidSudoku(board);
    cout << "Result: " << result << endl; // Output: 1 (true)
    return 0;
}