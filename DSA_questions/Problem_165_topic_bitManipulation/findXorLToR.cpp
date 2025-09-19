// User function Template for C++
#include <iostream>
using namespace std;
// time complexity : O(n) , space complexity : O(1)

class Solution {
  public:
    int findXOR(int l, int r) {
        // brute force do the loop from l to r
        int res = 0;
        for(int i = l;i<=r;i++){
            res = res^i;
        }
        return res;
    }
};
int main() {
    Solution sol;
    int l = 3, r = 9;
    cout << "XOR from " << l << " to " << r << " is: " << sol.findXOR(l, r) << endl;
    return 0;
}