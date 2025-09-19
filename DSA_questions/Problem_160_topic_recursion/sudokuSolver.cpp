#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// time complexity is O(1) and space complexity is O(1)
class Solution {
public:
    // board length is 9*9 so it would be O(1) and O(1) only 
    bool isValid(vector<vector<char>>& board,int row,int col,char num){
        // check for that row
        for(int i = 0;i<9;i++){
            if(board[row][i]==num) return false;
        }     
        // check for that col
        for(int i = 0;i<9;i++){
            if(board[i][col]==num) return false;
        }        
        // check for 3*3 boxes
        int boxstartrow = (row/3)*3;
        int boxstartcol = (col/3)*3;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(board[i+boxstartrow][j+boxstartcol]==num) return false;
            }
        }            
        return true;
    }
    bool solveIt(vector<vector<char>>& board){
        
        // step1 : put at every node the 1-9 numbers and see if it's valid , if it is go to the next indexes

        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                // so if there is an empty cell then only we need to check if we can do something for this
                if(board[i][j]=='.'){
                    for(char c = '1';c<='9';c++){
                        if(isValid(board,i,j,c)){
                            // place the number
                            board[i][j]=c;
                            // do the recursion again
                            if(solveIt(board)) return true;
                            // backtrack here 
                            board[i][j]='.';
                        }
                    }
                    return false; // no valid number found

                }
            }
        }
        return true; // found the board successfully
    }
    void solveSudoku(vector<vector<char>>& board) {
        // it is gurantted that there is a solution        
        solveIt(board);
    }
};
int main(){
    Solution s;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    s.solveSudoku(board);
    for(auto row : board){
        for(auto val : row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}
