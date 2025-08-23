#include <iostream>
#include <vector>
using namespace std;

// Total Complexity: We multiply the complexities of the nested parts.
// Total Time = (Outer Loop) × (Inner Loop) × (Work Inside)
// Total Time = O(m) * O(n) * O(1)
// Total Time = O(m * n)

// space complexity : O(1)
class Solution {
public:
    int calculateIt(int i,int j,vector<vector<int>>& grid){
        int res = 0;
        res = grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1]+grid[i][j]+grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
        return res;
    }
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int resfinal = 0;
        for(int i = 1;i<m-1;i++){
            for(int j = 1;j<n-1;j++){
                int res = calculateIt(i,j,grid);
                resfinal = max(resfinal,res);
            }
        }
        return resfinal;

    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 2, 3, 0, 0},
        {4, 5, 6, 0, 0},
        {7, 8, 9, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int result = sol.maxSum(grid);
    cout << "Maximum sum of hourglass: " << result << endl; // Output: Maximum sum of hourglass: 35
    return 0;
}