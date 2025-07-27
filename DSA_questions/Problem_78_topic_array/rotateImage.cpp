#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity : O(n^2) ==> O(n^2) for transposing the matrix + O(n^2) for reversing the rows
// space complexity : O(1) as we are not using any extra space
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // step 1 : transpose the matrix : only swap the upper triangle , we are ignoring lower triangle because it would undo the previous swap and also ignoring the digonal entries like i==j
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // step 2 : reverse the order of its rows
        for(int i = 0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(matrix);
    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
