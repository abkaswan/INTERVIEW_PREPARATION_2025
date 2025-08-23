#include <iostream>
#include <vector>
using namespace std;
// time complexity: O(n*m), space compleixity: O(1)
class Solution {
public:
    // i is row, j is column
    int countSquares(vector<vector<int>>& m) {
        int nS = m.size();
        int mS = m[0].size();
        int total = 0;
        
        // Call recursion for every cell
        for (int i = 0; i < nS; i++) {
            for (int j = 0; j < mS; j++) {
                if(i>0 && j>0 && m[i][j]==1)
                    m[i][j] += min({m[i-1][j],m[i][j-1],m[i-1][j-1]});
                total+=m[i][j];
            }
        }

        // for (int i = 0; i < nS; i++) {
        //     for (int j = 0; j < mS; j++) {
        //         total+=m[i][j];
        //     }
        // }
        

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