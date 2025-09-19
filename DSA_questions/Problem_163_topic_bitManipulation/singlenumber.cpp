#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n)
// space complexity : O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // do xor for all of them : we will get the answer 
        int res = 0;
        for(auto x : nums){
            res = res^x;
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = sol.singleNumber(nums);
    cout << "The single non-duplicate element is: " << result << endl;
    return 0;
}