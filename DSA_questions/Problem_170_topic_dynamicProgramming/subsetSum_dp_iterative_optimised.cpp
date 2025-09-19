#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n*sum) , space complexity : O(sum)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // method 1 : simple recursion
        // method 2 : dp with memoisation
        // method 3 : dp with iteartion
        // method 4 : dp with iteration optimised
        int n = arr.size();
        vector<bool> dp(sum+1,false);
        
        // the relation will be include and exclude and then check which one is maximum
        
        // sum of 0 will always be possible by choosing empty subset
        dp[0] = true;
        
        
        for(int i = 0;i<n;i++){
            for(int j = sum;j>=arr[i];j--){
                    // include and exclude the current element in both cases
                
                    // exclude the current element arr[i-1] so it would totally depend on the previois value
                    // now include the current element if it is possible and check again 
                    dp[j] = dp[j] || dp[j-arr[i]];
            }

        }
        
        
        // whether sum target is possible using all n elements
        return dp[sum];
        
    }
};
int main() {
    Solution solution;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    if (solution.isSubsetSum(arr, sum)) {
        cout << "Found a subset with the given sum" << endl;
    } else {
        cout << "No subset with the given sum" << endl;
    }
    return 0;
}