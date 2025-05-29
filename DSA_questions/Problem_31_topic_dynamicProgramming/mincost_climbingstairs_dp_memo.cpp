#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // tc : O(n) and sc : O(n) 
    int mincost(vector<int>& cost, int n,vector<int>& dp){
        if(n<0) return 0;
        if(n==0 || n==1) return cost[n];
        if(dp[n]!=-1) return dp[n];
        // take one step or take two steps
        return dp[n]=cost[n]+min(mincost(cost,n-1,dp),mincost(cost,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // method 1 ; recursion 
        // method 2 : top to bottom kinda
        int n = cost.size();
        vector<int> dp(n,-1);
        
        // when we jump only one index initially
        return min(mincost(cost,n-1,dp),mincost(cost,n-2,dp));
        
    }
};
int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    int result = sol.minCostClimbingStairs(cost);
    cout << "Result: " << result << endl;
    return 0;
}
