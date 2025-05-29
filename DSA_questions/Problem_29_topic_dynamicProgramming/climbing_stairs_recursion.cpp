#include <iostream>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        //1st method: recursion
        if(n==1) return 1;
        if(n==2) return 2;
        return climbStairs(n-1)+climbStairs(n-2);
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