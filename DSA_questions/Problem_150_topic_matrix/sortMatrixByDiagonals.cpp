#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// time complexity : O(n^2*logn) => O(n^2)+O(n^2*logn)+O(n^2)
// space complexity : O(n^2) => for the map as there are total n^2 elements so
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        unordered_map<int,vector<int>> mpp;
        
        // for diagonals if (i-j) is the same then they belong to the same diagonal , we can use map<int,vector<int>> or vector<vector<int>> to store these groupings , one more thing total number of diagonals is 2*n-1 calculate it or ask chatgpt
        
        
        // step 1 : get the groupings
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                mpp[i-j].push_back(grid[i][j]);
            }
        }
        // step 2 : sort them 
        for(auto& [key,vec]:mpp){
            // if bottom-left triangle -- do decreasing order
            if(key>=0){
                sort(vec.rbegin(),vec.rend());
            }
            // else do ascending order
            else{
                sort(vec.begin(),vec.end());
            }
        }

        // step 3 : put them back in the original grid
        // as the map will have i-j so the same way we stored same way we put it back 
        for(int i = n-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                grid[i][j] = mpp[i-j].back();
                mpp[i-j].pop_back();
            }
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