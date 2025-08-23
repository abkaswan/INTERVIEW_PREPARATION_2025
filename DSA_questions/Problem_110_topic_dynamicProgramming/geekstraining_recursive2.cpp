#include <iostream>
#include <vector>
using namespace std;

// Time complexity :
//     Day 1 (i = 0) has 3 choices.
//     Every subsequent day has at most 2 choices (because you can’t repeat the previous activity).
//     Number of leaves (complete sequences) = 3 * 2^(n-1) which is Θ(2^n).
//     Each recursive[[] call does a constant amount of work (loop of 3 with O(1) operations), so the overall time complexity is Θ(2^n) (exponential).

// Space complexity :
//     The recursion depth is n (one stack frame per day), so the call-stack (auxiliary) space is O(n).
//     Besides the stack, you only use O(1) extra space (a few integers), so total extra space is O(n).
// note : with large n such as 10^5 the exponential recursion is infeasible and stack overflow for the recursive stack will be there. so this is for small n like n=30 

class Solution {
  public:
    int chooseRow(int i,int prev,const vector<vector<int>>& arr){
        if(i>=arr.size()){  // base case ; no rows left
            return 0;
        }
        int best = 0;
        for(int j = 0;j<3;j++){
            if(j==prev) continue;
            int curr = arr[i][j]+chooseRow(i+1,j,arr);
            best = max(best,curr);
        }
        return best;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // step 1 : LET'S TRY THE RECURSION METHOD FIRST
        return chooseRow(0,-1,arr);
        
    }
};
int main() {
    Solution sol;
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int result = sol.maximumPoints(arr);
    cout << "Maximum Points: " << result << endl;
    return 0;
}