#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int tribonacciNew(int n,vector<int>& v) {
        // m1 : use recursive method 
        // m2 : using memoization in the same. so O(n) tc and O(n) sc
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(v[n]!=-1) return v[n];
        return v[n]=tribonacciNew(n-1,v)+tribonacciNew(n-2,v)+tribonacciNew(n-3,v);
    }
    int tribonacci(int n) {
        // m1 : use recursive method 
        // m2 : using memoization in the same. so O(n) tc and O(n) sc
        vector<int> v(n+1,-1);
        return tribonacciNew(n,v);
    }
};
int main() {
    Solution sol;
    int n = 25;
    cout << sol.tribonacci(n) << endl;
    return 0;
}
