#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(logn) space complexity : O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        // do xor and then calculate the number of 1s that are there
        // why : because we need how many bits are different in both numbers if we xor it we will get the number
        int res = start^goal, count = 0;
        // convert to binary 
        while(res){
            if(res%2==1) count++;
            res = res/2;
        }
        return count;
    }
};
int main() {
    Solution sol;
    int start = 10, goal = 7;
    cout << "Minimum bit flips to convert " << start << " to " << goal << ": " 
         << sol.minBitFlips(start, goal) << endl; // Output: 3
    return 0;
}