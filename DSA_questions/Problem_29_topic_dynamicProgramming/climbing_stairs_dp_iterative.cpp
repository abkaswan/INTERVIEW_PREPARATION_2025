#include <iostream>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        //1st method: recursion , 2nd method : dp memoization , 3rd method : tabulation iterative(bottom up)
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int prev2 = 1, prev1 = 2,curr;
        for(int i=3;i<=n;i++)
        {
            curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
int main() {
    Solution sol;
    int n;
    cout<<"Enter the number of steps : ";
    cin>>n;
    cout<<"Number of distinct ways to climb to the top : "<<sol.climbStairs(n);
    return 0;
}