#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// time complexity O(n) and space complexity O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // method 2 : use same prefixhashmap and all for the count right : O(n) tc and O(n) sc
        unordered_map<int,int> mpp;
        mpp[0]=1;//when prefixSum == goal in that case

        int n = nums.size();
        int count = 0,sum = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            if(mpp.count(sum-goal))
            {
                count+=mpp[sum-goal];
            }
            mpp[sum]++;
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    int result = sol.numSubarraysWithSum(nums, goal);
    // Output the result
    cout << "Number of subarrays with sum " << goal << ": " << result << endl;
    return 0;
}