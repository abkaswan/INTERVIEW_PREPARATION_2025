#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size(); 
        vector<int> v;
        // go to i = 0 , j = 0 to n-1
        // go to j = n-1, i = 1 to m-1
        // go to i = m-1, j = n-2 to 0 
        // go to j = 0, i = m-2 to 1
        // go to i = 1 , j = 1 to n-2 
        // go to j = n-2, i = 2 to m-2
        // go to i = m-2, j = n-3 to 1
        int top = 0, bottom = m-1;
        int left = 0, right = n-1;
        while(top<=bottom && left<=right)
        {
            // top row 
            for(int i=left;i<=right;i++){
                v.push_back(matrix[top][i]);
            }
            top++;
            // right column
            for(int i=top;i<=bottom;i++){
                v.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                // bottom row
                for(int i=right;i>=left;i--){
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                // left column
                for(int i=bottom;i>=top;i--){
                    v.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return v;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result = sol.spiralOrder(matrix);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}