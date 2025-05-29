#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        // m1 : use recursive method 
        // m2 : using memoization in the same. so O(n) tc and O(2n) sc
        // m3 : using tabulation(bottom to top) for the same method instead of memoization of top to bottom- tc : O(n) and sc : O(n)
        // m4 : use maybe the three pointers approach here
        int prev3 = 0, prev2 = 1, prev1 = 1,curr;
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        for(int i=3;i<=n;i++){
            curr = prev1+prev2+prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
int main() {
    Solution sol;
    int n = 25;
    cout << sol.tribonacci(n) << endl;
    return 0;
}
