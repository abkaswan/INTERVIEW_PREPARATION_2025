#include <iostream>
#include <vector>

using namespace std;
// time complexity : O(n^2)
// space complexity : O(1)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // so if i,i is 1 there might be other entires right
        
        // brute force : two for loops
        int n = mat.size();
        for(int i = 0;i<n;i++){
            bool knowsNobody = true;
            bool knowsByAll = true;
            
            // check row i , i should not know anyone else
            for(int j = 0;j<n;j++){
                if(i!=j && mat[i][j]==1){
                    knowsNobody = false;
                    break;
                }
            }
            
            // check col i (everyone else should know i)
            for(int j = 0;j<n;j++){
                if(i!=j && mat[j][i]!=1){
                    knowsByAll = false;break;
                }
            }
            
            if(knowsNobody && knowsByAll) return i;
        }
        return -1;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 0}
    };
    int result = sol.celebrity(mat);
    cout << "The celebrity is at index: " << result << endl; // Output: The celebrity is at index: 1
    return 0;
}