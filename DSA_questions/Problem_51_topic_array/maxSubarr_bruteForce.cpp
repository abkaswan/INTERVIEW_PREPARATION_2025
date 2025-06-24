#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // brute force : two for loops , O(n^2) time and O(1) space
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // example input
    Solution sol;
    int maxSum = sol.maxSubArray(nums);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

