#include <iostream>
#include <vector>
using namespace std;
// Time Complexity: O(n)
// The time complexity is O(n) because we are simply iterating the array once from start to finish. 

// Space Complexity: O(n)
// The space complexity is O(n) because we are storing the dp array of size n.
// Each element of the dp array will store the minimum cost of the frog to reach the i-th stone.

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        dp[1]=abs(height[0]-height[1])+dp[0];
        
        for(int i = 2;i<n;i++){
            dp[i] = min((abs(height[i-1]-height[i])+dp[i-1]),(abs(height[i-2]-height[i])+dp[i-2]));
        }
        return dp[n-1];
    }
};

int main() {
    vector<int> height = {10, 30, 40, 20}; // example heights
    Solution sol;
    int result = sol.minCost(height);
    cout << "Minimum cost to reach the last stone: " << result << endl;
    return 0;
}

