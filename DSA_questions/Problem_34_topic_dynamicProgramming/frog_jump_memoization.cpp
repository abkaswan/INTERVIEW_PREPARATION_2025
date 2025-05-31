#include <iostream>
#include <vector>
using namespace std;
// Time Complexity: O(n)
// Explanation: The function minCostRe is called for each index from 0 to n-1, where n is the size of the height vector.
// Each call computes the result using previously stored values in the dp array, ensuring each state is computed once.
// Hence, the time complexity is O(n).

// Space Complexity: O(n)
// Explanation: The space complexity is O(n) due to the dp array used for memoization, which stores the result of each state 
// to avoid redundant calculations. The recursive call stack also has a maximum depth of n, but the dp array is the primary contributor.

class Solution {
  public:
    int minCostRe(vector<int>& height,int i,vector<int>& dp){
        if(i==height.size()-1) return 0; //at the last stair so no cost to pay
        if(i>=height.size()) return INT_MAX/2; // to prevent potential overflow 
        if(dp[i]!=-1) return dp[i];
        return dp[i]=min(abs(height[i]-height[i+1])+minCostRe(height,i+1,dp),abs(height[i]-height[i+2])+minCostRe(height,i+2,dp));
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n-1,-1);
        
        return minCostRe(height,0,dp);
    }
};

int main() {
    vector<int> height = {10, 30, 40, 20}; // example heights
    Solution sol;
    int result = sol.minCost(height);
    cout << "Minimum cost to reach the last stone: " << result << endl;
    return 0;
}

