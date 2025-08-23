#include <iostream>
#include <vector>
using namespace std;

// Time complexity :
// as we are storing all the possiblities in O(4*n) so after that anything comes then take it from there
// Space complexity :
//     The recursion depth is n (one stack frame per day), so the call-stack (auxiliary) space is O(n).
//     Besides the stack, you use O(4*n) extra space for vector

class Solution {
  public:
    vector<vector<int>> memo; // initially it would be -1 then better
    int chooseRow(int i,int prev,const vector<vector<int>>& arr){
        if(i>=arr.size()){  // base case ; no rows left
            return 0;
        }
        if(memo[i][prev]!=-1) return memo[i][prev];
        int best = 0;
        for(int j = 0;j<3;j++){
            if(j==prev) continue;
            int curr = arr[i][j]+chooseRow(i+1,j,arr);
            best = max(best,curr);
        }
        memo[i][prev] = best;
        return best;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // step 1 : LET'S TRY THE RECURSION METHOD FIRST
        memo.assign(arr.size(), vector<int>(4, -1)); // prev indices 0,1,2 and 3 => no previous
        return chooseRow(0,3,arr);
        
    }
};
int main() {
    Solution sol;
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int result = sol.maximumPoints(arr);
    cout << "Maximum Points: " << result << endl;
    return 0;
}