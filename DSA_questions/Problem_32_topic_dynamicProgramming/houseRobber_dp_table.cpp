#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        // recursive apporoach : O(2^n)
        // method 2 : trying top to bottom -- memoization , O(2N) tc and O(N) sc
        // method 3 : bottom to up -- iterative approach
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n,-1);

        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=nums[2]+max(dp[0],0);
        for(int i = 3;i<n;i++){
            dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
        }
        return max(dp[n-1],dp[n-2]);

    }
};
int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // example input
    Solution sol;
    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}

