#include <iostream>
using namespace std;
// time complexity : O(n) , space complexity : O(1)
class Solution {
  public:
    int xorTillN(int n){
        if(n%4==0) return n;
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        return 0;
        
    }
    int findXOR(int l, int r) {
        // brute force do the loop from l to r
        // another method remember if you do xor from 0 to n you will see that if n%4==0 it will be n , n%4==1 then it will be 1 , n%4==2 it will be n+1 , if n%4==3 it will be 0 , 
        // now we can say xor(l to r) = xor(0 to r) ^ xor(0 to l-1) right 
        return xorTillN(r)^xorTillN(l-1);
    }
};
int main() {
    Solution sol;
    int l = 3, r = 9;
    cout << "XOR from " << l << " to " << r << " is: " << sol.findXOR(l, r) << endl;
    return 0;
}