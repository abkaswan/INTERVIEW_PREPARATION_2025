#include <iostream>
#include <vector>
using namespace std;
// Time Complexity: O(n) (one pass)
// Space Complexity: O(1) (just a few integers)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0, n = nums.size();
        
        for(int i = 0;i<n;i++){
            if(i>maxReach) return false;
            maxReach = max(maxReach,i+nums[i]);
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    bool result = sol.canJump(nums);
    cout << (result ? "true" : "false") << endl; // Expected output: true
    return 0;
}