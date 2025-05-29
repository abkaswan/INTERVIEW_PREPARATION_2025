#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        // m1 : use recursive method 
        // m2 : using memoization in the same. so O(n) tc and O(2n) sc
        // m3 : using tabulation(bottom to top) for the same method instead of memoization of top to bottom- tc : O(n) and sc : O(n)
        vector<int> dp(n+1,-1);
        dp[0]=0;
        if(n>=1) dp[1]=1;
        if(n>=2) dp[2]=1;

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};
int main() {
    Solution sol;
    int n = 25;
    cout << sol.tribonacci(n) << endl;
    return 0;
}
