#include <iostream>
#include <cmath>
using namespace std;
// time complexity : O(1)
// space complexity : O(1)
class Solution {
  public:
    int setBit(int n) {
        // n+1 , it sets the rightmost 0 to 1 , and all the 1s after that to 0s , left of rightmost bit remains the same
        // so when we do that n|(n+1) it converts the rightmost 0 to 1 as we wanted and doesn't affect all the other bits
        return n|(n+1);
    }
};
int main() {
    Solution sol;
    int n = 18; // Example input
    int result = sol.setBit(n);
    std::cout << "Result: " << result << std::endl; // Expected output: 19
    return 0;
}