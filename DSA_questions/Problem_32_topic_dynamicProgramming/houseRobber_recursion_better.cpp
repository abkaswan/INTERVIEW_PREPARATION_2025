// why it's better : 
// Simpler base cases
// More intuitive decision-making at each step
// Clearer representation of the problem constraints
// Easier to modify for dynamic programming optimization

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // Time: O(2^N) - binary tree of recursive calls
    // Space: O(N) - maximum recursion depth
    int robSum(vector<int>& nums, int n){
        if(n<0) return 0;
        return max(nums[n]+robSum(nums,n-2),robSum(nums,n-1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return robSum(nums,n-1);
    }
};
int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // example input
    Solution sol;
    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}

