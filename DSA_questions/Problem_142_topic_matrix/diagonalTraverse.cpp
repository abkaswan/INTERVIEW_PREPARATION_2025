#include <iostream>
#include <vector>
using namespace std;
// time complexity: O(m*n)
// space complexity: O(m*n)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // the smallest diagonal index (i + j) = 0 (top-left element). The largest diagonal index = (m-1) + (n-1) = m + n - 2. (bottom-right element) so total number of diagonals = m+n-1
        vector<vector<int>> v(m+n-1);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                v[i+j].push_back(mat[i][j]);
            }
        }

        //now we have all the diagonals in groups so append it in the result vector -- if it is in even index as it is -- if it in odd index reverse it to make it zig zag order
        vector<int> res;
        for(int i = 0;i<m+n-1;i++){
            if(i%2==0){
                // append it in reverse
                for(int j = v[i].size()-1; j>=0;j--){
                    res.push_back(v[i][j]);
                }
            }
            else{
                //append it as it is
                for(int j = 0; j< v[i].size();j++){
                    res.push_back(v[i][j]);
                }
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result = sol.findDiagonalOrder(mat);
    cout << "Diagonal traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
