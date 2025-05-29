#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // tc : O(n) and sc : O(n) 
    int minCostClimbingStairs(vector<int>& cost) {
        // method 1 ; recursion 
        // method 2 : top to bottom approach : memoization 
        // method 3 : bottom to up approach : tabulation
        int n = cost.size();
        vector<int> dp(n,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};
int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    int result = sol.minCostClimbingStairs(cost);
    cout << "Result: " << result << endl;
    return 0;
}
