// time complexity ; O(n + m) where m is the maximum number in array : nums == total O(m+n)
// space complexity : O(m) to store the vector v + O(m) size for the dp + recursion stack can go upto depth m == total O(3m) 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int houseRobber(vector<int>& v,int n,vector<int>& dp){
        if(n<0) return 0;
        if(n==0 || n==1) return v[n];
        if(dp[n]!=-1) return dp[n];
        return dp[n]=v[n]+max(houseRobber(v,n-2,dp),houseRobber(v,n-3,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        // turn this into house robber problem 
        vector<int> v(10001,0);
        for(int i = 0;i<nums.size();i++){
            v[nums[i]]+=nums[i];
        }

        //now we have the i:the number and v[i]: as the count of that number
        // need to ignore i+1 and i-1 , we don't need to include those , and get the max count we can get , same as house robber problem
        int n = 10001;
        vector<int> dp(n+1,-1);
        return max(houseRobber(v,n-1,dp),houseRobber(v,n-2,dp));
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    int result = sol.deleteAndEarn(nums);

    cout << "Result: " << result << endl;

    return 0;
}
