#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity : O(2^n) , space complexity : O(n)
class Solution {
  public:
    bool allsubsets(int i, vector<int>& arr, int target,int sum){
      if(sum==target){
        return true;
      }
      if(i>=arr.size() || sum>=target){ //break it or return it not possible
        return false;
      }

      // include the current arr[i] for the sum 
      // exclude the current arr[i] for the sum 
      return allsubsets(i+1,arr,target,sum+arr[i]) || allsubsets(i+1,arr,target,sum);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // method 1 : simple recursion
        return allsubsets(0,arr,sum,0);
        
    }
};
int main() {
    Solution sol;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    if (sol.isSubsetSum(arr, sum))
        cout << "Found a subset with given sum" << endl;
    else
        cout << "No subset with given sum" << endl;
    return 0;
}