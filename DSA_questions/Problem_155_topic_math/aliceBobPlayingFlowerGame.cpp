#include <iostream>
using namespace std;
// time complexity: O(1), space complexity: O(1)

// You’ve got it—the whole game boils down to parity of the total flowers.
// Each turn removes exactly one flower (from either lane).
// So the game lasts exactly x + y moves.
// Alice plays on moves 1, 3, 5, … (odd moves). She wins iff the last move number is odd.
// Therefore, Alice wins ⇔ x + y is odd (the piles have opposite parity).

// #odd in [1, n] = ⌈n/2⌉
// #even in [1, n] = ⌊n/2⌋
// #odd in [1, m] = ⌈m/2⌉
// #even in [1, m] = ⌊m/2⌋
// Number of winning pairs:
// ans = ⌈n/2⌉ * ⌊m/2⌋ + ⌊n/2⌋ * ⌈m/2⌉
// This simplifies to:
// ans = ⌊(n * m) / 2⌋

class Solution {
public:
    long long flowerGame(int n, int m) {
        return 1LL*n*m/2;
    }
};
int main() {
    Solution sol;
    int n = 3, m = 3;
    long long result = sol.flowerGame(n, m);
    cout << "Result: " << result << endl; // Output: 4
    return 0;
}