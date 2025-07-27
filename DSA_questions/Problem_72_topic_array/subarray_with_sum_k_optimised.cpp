#include <iostream>
#include <vector>
using namespace std;
// time O(n)
// space O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // method 2 : use prefix sum  -- from index 0 to i what the sum is that is prefix sum for that subarray
        // now we know that if we are at index j then prefixSum[j]-prefixSum[i]= k then there is subarray from i+1 to j sums to k right ? now in the same way we can say , prefixSum[i] = sum-k if this exists then it is possible that subarray , so use this method
        unordered_map<int,int> mpp;
        mpp[0]=1; // for case where prefixSum = k then we need to count it and freq in that case will be 1
        int n = nums.size();
        int count = 0,sum = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            if(mpp.count(sum-k)) // if that is there we are checking
            {
                // then count is there , how many that depends on the freq
                count+=mpp[sum-k];
            }
            mpp[sum]++;
        } 
        return count;
        
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << sol.subarraySum(nums, k) << endl;  // Output: 2
    return 0;
}