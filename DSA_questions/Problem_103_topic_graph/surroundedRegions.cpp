#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // time complexity : O(m*n) - we call O(m+n) times dfs and across all calls it might visit each node so O(m*n) which is total O(m*n)+O(m+n) AND O(m*n) last for loop  so total is O(m*n) only right ?
    // space complexity :O(m*n) - dfs recusive stack only which will have at most O(m*n) space  
    int m,n;
    void dfs(vector<vector<char>>& board,int i, int j){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!='O') return;
        // convert the 'O's for now in something else let's say 'N' N - not change
        board[i][j] = 'N';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1); 
    }
    void solve(vector<vector<char>>& board) {
        // hmm one thing for this probem : if the border 0 is connected to another 0s then that is also considered border one only if you know what i mean so need to use dfs most easy solutoin to identify those traitors and apart from those replace all other 'O's
        

        // step 1 : dfs for all border 'O's
        m = board.size(); // this means rows
        n = board[0].size(); // this means cols

        // left and right rows
        for(int i = 0;i<m;i++)
        {
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][n-1]=='O') dfs(board,i,n-1);
        }
        // top and bottom rows
        for(int j = 1;j<n-1;j++)
        {
            if(board[0][j]=='O') dfs(board,0,j);
            if(board[m-1][j]=='O') dfs(board,m-1,j);
        }

        //step 2: flip surrounded 'O' to 'X' , change 'N' back to "O"
        for(int i = 0;i<m; i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='N') board[i][j]='O';

            }
        }
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