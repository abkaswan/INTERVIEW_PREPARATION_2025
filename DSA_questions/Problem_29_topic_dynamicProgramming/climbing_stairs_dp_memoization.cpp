#include <iostream>

using namespace std;
class Solution {
public:
    int climb(int n , vector<int>& v){
        if(n==1) return 1;
        if(n==2) return 2;
        if(v[n]!=-1) return v[n];
        return v[n]=climb(n-1,v)+climb(n-2,v);
    }
    int climbStairs(int n) {
        //1st method: recursion , 2nd method : dp memoization
        vector<int> v(n+1,-1);
        return climb(n,v);
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