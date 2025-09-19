#include <iostream>
#include <vector>
using namespace std;
// time complexity: O(n)
// space complexity: O(1)
class Solution {
public:
//     Why we need both currMax and currMin -->
//     Negative numbers flip the situation:
//     If you have a large positive product (currMax) and multiply by a negative, it becomes a large negative.
//     If you have a large negative product (currMin) and multiply by a negative, it becomes a large positive → potential new maximum.
//     So at each step, the best product could come from either:
//         ->Starting fresh from nums[i],
//         ->Extending the old currMax with nums[i], or
//         ->Extending the old currMin with nums[i] (because a negative * negative can beat the old max).
//     That’s why we need both.

// Why swapping happens -->
//      When we see nums[i] < 0, multiplying will swap roles:
//      What used to be the max might now become the min.
//      What used to be the min might now become the max.
// So we literally swap(currMax, currMin) before updating.
    int maxProduct(vector<int>& nums) {
        int maxPdt = nums[0],currentPdtMax = nums[0],currentPdtMin = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i]<0) swap(currentPdtMin,currentPdtMax);
            currentPdtMax = max(nums[i],currentPdtMax*nums[i]);
            currentPdtMin = min(nums[i],currentPdtMin*nums[i]);

            maxPdt = max(maxPdt,currentPdtMax);
        }
        return maxPdt;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2,3,-2,4};
    cout << sol.maxProduct(nums) << endl; // Output: 6
    return 0;
}