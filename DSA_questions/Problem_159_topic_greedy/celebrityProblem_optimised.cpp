#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n)
// space complexity : O(1)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // so if i,i is 1 there might be other entires right
        
        // another method : i,j means i knows j so j cannot be celebrity , i,j --> i not know j , that means j cannnot be celebritiy 
        // after getting your answer double check it by row and cols , because we do not know that the last we selected is truly a celebrity
        
        // we can also use stack here we can enter each element in stack and then pop two elements and check if one knows other or not but that will take O(n) space so this is better
        int candidate = 0;
        int n = mat.size();
        
        // step 1 : start elemination
        for(int i = 1;i<n;i++){
            if(mat[candidate][i]==1){
                //candidate knows i so candidate can't be celebrity 
                candidate = i;
            }
            // else i cannot be celebrity right so go as it is
        }
        
        // step 2 : check our candidate if that is the celebrity 
        // check candidate as row it should be false
        // check canddiate as col it should be true
        for(int j = 0;j<n;j++){
            if(j!=candidate){
                if(mat[candidate][j]==1) return -1;
                if(mat[j][candidate]==0) return -1;
            }
        }
        return candidate;
        
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