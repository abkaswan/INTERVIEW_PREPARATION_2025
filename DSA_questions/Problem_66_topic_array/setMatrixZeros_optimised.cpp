#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(m*n)
// space complexity : O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool firstRowZero = false, firstColZero = false;
        for(int j = 0;j<n;j++){
            if(matrix[0][j]==0) firstRowZero = true;
        }
        for(int i = 0;i<m;i++){
            if(matrix[i][0]==0) firstColZero = true;
        }
        // instead of two vectors use the first row and col for the storing of vector 
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // now use this another for loop to fix that
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j]=0;
            }
        }
        // finally zero the first row and col if needed
        if(firstRowZero){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(firstColZero){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    sol.setZeroes(matrix);
    
    cout << "Matrix after setting zeroes:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}