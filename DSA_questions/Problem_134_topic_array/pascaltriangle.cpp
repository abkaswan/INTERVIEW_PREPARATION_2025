#include <iostream>
#include <vector>
using namespace std;
// Time Complexity : O(n^2) where n is the number of rows in the triangle
// Space Complexity : O(n^2) for the v table, where n is the number of rows in the triangle
class Solution {
public:
    vector<vector<int>> generate(int n) {
        // pascal's triangle : so noticed that the corners will be 1 and the others like [i][j] = [i-1][j-1]+[i-1][j] right ?
        vector<vector<int>> v(n);
        for(int i = 0;i<n;i++){
            v[i].assign(i+1,1);
        }

        for(int i = 2;i<n;i++){
            for(int j = 1;j<i;j++){
                v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
        }
        return v;
    }
};
int main() {
    Solution sol;
    int numRows = 5;
    vector<vector<int>> result = sol.generate(numRows);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}