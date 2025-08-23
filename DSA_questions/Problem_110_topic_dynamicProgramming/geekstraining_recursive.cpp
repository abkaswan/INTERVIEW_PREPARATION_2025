#include <iostream>
#include <vector>
using namespace std;

// Time complexity :
//     Day 1 (i = 0) has 3 choices.
//     Every subsequent day has at most 2 choices (because you can’t repeat the previous activity).
//     Number of leaves (complete sequences) = 3 * 2^(n-1) which is Θ(2^n).
//     Each recursive call does a constant amount of work (loop of 3 with O(1) operations), so the overall time complexity is Θ(2^n) (exponential).

// Space complexity :
//     The recursion depth is n (one stack frame per day), so the call-stack (auxiliary) space is O(n).
//     Besides the stack, you only use O(1) extra space (a few integers), so total extra space is O(n).
// note : with large n such as 10^5 the exponential recursion is infeasible and stack overflow for the recursive stack will be there. so this is for small n like n=30 

class Solution {
  public:
    void chooseRow(int i,int& count,int& res,int prev,const vector<vector<int>>& arr){
        if(i>=arr.size()){ 
            res = max(res,count);
            return;
            
        }
        for(int j = 0;j<3;j++){
            if(j!=prev){
                count+=arr[i][j];
                chooseRow(i+1,count,res,j,arr);
                count-=arr[i][j];
            }
        }
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // step 1 : LET'S TRY THE RECURSION METHOD FIRST
        int res = 0,count = 0;
        chooseRow(0,count,res,-1,arr);
        
        return res;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int result = sol.maximumPoints(arr);
    cout << "Maximum Points: " << result << endl;
    return 0;
}