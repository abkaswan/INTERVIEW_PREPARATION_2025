#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // time complexity : O(2^n)
    // space complexity : O(n)
    int robHouse(vector<int>& nums,int n,int start){
        if(n<start) return 0;
        return nums[n]+max(robHouse(nums,n-2,start),robHouse(nums,n-3,start));
    }
    int helper(vector<int>& nums,int n, int start){
        // so for subarray 0 to n-2 it will take n-2 and n-3
        // for subarray 1 to n-1 it will take n-1 and n-2 to perform the robSum function
        return max(robHouse(nums,n,start),robHouse(nums,n-1,start));
    }
    int rob(vector<int>& nums) {
        // method 1 : recursion
        int n = nums.size();
        if(n==1) return nums[0];
        return max(helper(nums,n-2,0),helper(nums,n-1,1));
    }
};
int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // example input
    Solution sol;
    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}
