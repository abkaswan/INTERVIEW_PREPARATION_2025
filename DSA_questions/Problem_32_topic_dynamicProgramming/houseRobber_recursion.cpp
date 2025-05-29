#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int robSum(vector<int>& nums, int n){
        if(n<0) return 0;
        if(n==0 || n==1) return nums[n];
        return nums[n]+max(robSum(nums,n-2),robSum(nums,n-3));
        
    }
    int rob(vector<int>& nums) {
        // recursive apporoach : O(2^n)
        int n = nums.size();
        return max(robSum(nums,n-1),robSum(nums,n-2));

    }
};
int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // example input
    Solution sol;
    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}

