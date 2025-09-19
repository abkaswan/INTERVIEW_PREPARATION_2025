#include <iostream>
#include <vector>
using namespace std;
// time complexity: O(n)
// space complexity: O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // another way to see this is that we can place one place from 1->0 and then can see after placing where we are getting the largest subarray
        // and if there is no zero do -1 instead

        // so in sliding window if there is 0 coming let it come but only one time 
        int zeros = 0; // take count of zero
        int l = 0, r = 0;
        int n = nums.size(),maxLen = 0;
        while(r<n){
            if(nums[r]==0) zeros++;
            
            // keep shrinking until there is only one 0
            while(zeros>1){
                if(nums[l]==0) zeros--;
                l++;
            }
            
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        //because you need to remove the element you are removing right so in case if zeroes are there we would have removed it and in case one are there also we have removed something
        return maxLen-1;

    }

};

int main() {
    Solution sol;
    vector<int> nums = {1,1,0,1};
    int result = sol.longestSubarray(nums);
    cout << "Longest subarray of 1s after deleting one element: " << result << endl; // Output: 3
    return 0;
}