#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // tc : O(2^n)
    int mincost(vector<int>& cost, int n){
        if(n<0) return 0;
        if(n==0 || n==1) return cost[n];
        // take one step or take two steps
        return cost[n]+min(mincost(cost,n-1),mincost(cost,n-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // method 1 ; recursion 
        // when we jump only one index initially
        return min(mincost(cost,cost.size()-1),mincost(cost,cost.size()-2));
        
    }
};
int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    int result = sol.minCostClimbingStairs(cost);
    cout << "Result: " << result << endl;
    return 0;
}
