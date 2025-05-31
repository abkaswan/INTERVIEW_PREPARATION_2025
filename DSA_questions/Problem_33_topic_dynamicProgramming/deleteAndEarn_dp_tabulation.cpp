// time complexity ; O(n + m) where m is the maximum number in array : nums == total O(m+n)
// space complexity : O(m) to store the vector v + O(m) size for the dp == total O(2m) 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // turn this into house robber problem 
        vector<int> v(10001,0);
        for(int i = 0;i<nums.size();i++){
            v[nums[i]]+=nums[i];
        }

        //now we have the i:the number and v[i]: as the count of that number
        // need to ignore i+1 and i-1 , we don't need to include those , and get the max count we can get , same as house robber problem
        int n = v.size();
        vector<int> dp(n,-1);
        dp[0] = v[0];
        dp[1] = v[1];
        dp[2] = v[2]+max(dp[0],0);
        for(int i = 3;i<n;i++){
            dp[i] = v[i]+max(dp[i-2],dp[i-3]);
        }
        return max(dp[n-1],dp[n-2]);
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    int result = sol.deleteAndEarn(nums);

    cout << "Result: " << result << endl;

    return 0;
}