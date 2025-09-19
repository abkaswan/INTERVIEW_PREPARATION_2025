#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 🔹 Time Complexity
// We are processing each diagonal one by one.
// 1. Collecting + Writing back elements
//     For each diagonal of length k, collecting and putting back elements takes O(k).
//     Across all diagonals, total elements = n^2.
//     So overall traversal = O(n^2).

// 2. Sorting each diagonal -->
//     Sorting a diagonal of length k takes O(k log k).
//     Across all diagonals, sum of all lengths = n^2. so O(n^2*logn)
//     (because the longest diagonal has length n, and total elements are n^2).
// 👉 Total Time Complexity = O(n^2 log n)

// 🔹 Space Complexity
// Extra storage for one diagonal (diag) At most size n. So O(n) auxiliary space.
// 👉 Total Space Complexity = O(n)

class Solution {
public:
    
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // for diagonals if (i-j) is the same then they belong to the same diagonal , we can use map<int,vector<int>> or vector<vector<int>> to store these groupings , one more thing total number of diagonals is 2*n-1 calculate it or ask chatgpt , now there is another method where we will process one diagonal at a time , int htat case we will neeed to use only one vector and the space complexity would be O(n)

        auto processDiagonal = [&](int starti, int startj){
            vector<int> diag;
            int i = starti,j = startj;

            // step 1 : collect elements from diagonal
            while(i<n && j<n){
                diag.push_back(grid[i++][j++]);
            }

            // step 2 : sort the diagonal
            int key = starti-startj;
            // descending order
            if(key>=0){
                sort(diag.rbegin(),diag.rend());
            } //else ascending order
            else{
                sort(diag.begin(),diag.end());
            }

            //step 3 : put them back
            i = starti, j = startj;
            int index = 0;
            while(i<n && j<n){
                grid[i][j] = diag[index];
                i++;
                j++;
                index++;
            }


        };

        // process diagonal starting from the first row
        for(int j = 0;j<n;j++){
            processDiagonal(0,j);
        }
        // process diagonal starting from the first column
        for(int i = 0;i<n;i++){
            processDiagonal(i,0);
        }
        return grid;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {{3, 2, 1}, {6, 5, 4}, {9, 8, 7}};
    vector<vector<int>> sortedGrid = sol.sortMatrix(grid);
    for (const auto& row : sortedGrid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}