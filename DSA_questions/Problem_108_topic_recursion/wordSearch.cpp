#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Time Complexity: O(N * M * 4^L)

// N = number of rows in the board
// M = number of columns in the board
// L = length of the word to be searched
// Explanation:
// The main function iterates through each cell of the board: O(N * M)
// For each cell, we perform DFS that explores in 4 directions (up, down, left, right)
// At each step of DFS, we have 4 choices and we can go up to L steps deep (length of word)
// Hence, for each starting position, the DFS can take up to 4^L time
// Total time complexity: O(N * M) * O(4^L) = O(N * M * 4^L)

// Space Complexity: O(L)

// The space complexity : O(L) where L is the length of the word
// This comes from the recursion stack depth in the DFS
// We don't use any extra space proportional to the board size since we modify the board in-place using '#' to mark visited cells and restore it back after exploration
// The recursion can go as deep as the length of the word we're searching for

class Solution {
public:
    bool dfs(int i,int j, vector<vector<char>>& board, string& word,int x){
        if(x==word.size())    return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        if(board[i][j]!=word[x]) return false;
        
        char temp = board[i][j]; //save original letter
        board[i][j]='#'; // mark visited
        
        // we will go to all four directions
        bool found = dfs(i+1,j,board,word,x+1) || dfs(i-1,j,board,word,x+1) || dfs(i,j+1,board,word,x+1) || dfs(i,j-1,board,word,x+1);

        board[i][j]=temp;// replace after exploring
        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Build char frequencies:
        vector<int> freq(128, 0);
        for (auto& row : board)
            for (char c : row)
                freq[c]++;

        // Reverse word if last char is rarer than the first:
        if (freq[word.back()] < freq[word.front()]) {
            reverse(word.begin(), word.end());
        }

        // Optional: early exit if board lacks sufficient frequency:
        vector<int> need(128, 0);
        for (char c : word) {
            if (++need[c] > freq[c]) return false;
        }
        
        // now do the dfs serach for the word[0] into grid , so use all 4-directions method for this one 
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]==word[0] && dfs(i,j,board,word,0)) return true;
            }
        }
        return false;

    }
};
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    bool result = sol.exist(board, word);
    cout << (result ? "true" : "false") << endl;
    return 0;
}