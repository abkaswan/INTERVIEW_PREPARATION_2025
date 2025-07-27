#include <iostream>
using namespace std;
// time complexity: O(1)
// space complexity: O(1)
class Solution {
  public:
    pair<int, int> get(int a, int b) {
        a = a^b;
        b = a^b;
        a = a^b;
        return {a,b};
    }
};
int main() {
    Solution sol;
    int a = 5, b = 10;
    pair<int, int> result = sol.get(a, b);
    // Output the swapped values
    cout << "Swapped values: " << result.first << ", " << result.second << endl;
    return 0;
}