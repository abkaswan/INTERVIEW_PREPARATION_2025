#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // tc : O(n) and sc : O(1) 
    int minCostClimbingStairs(vector<int>& cost) {
        // method 1 ; recursion 
        // method 2 : top to bottom approach : memoization 
        // method 3 : bottom to up approach : tabulation
        // method 4 : pointers approach maybe
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];
        int curr;
        for(int i = 2;i<n;i++){
            curr=cost[i]+min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1,prev2);
    }
};
int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    int result = sol.minCostClimbingStairs(cost);
    cout << "Result: " << result << endl;
    return 0;
}
