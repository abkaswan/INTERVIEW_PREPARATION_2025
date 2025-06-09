#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// time complexity : O(logn)
// sc : O(1)
class Solution {
public:
    // modified binary search : 
    // at each step check if the left half or right half is sorted , then decide whether to go left/right.
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target) return mid;
            
            // left half is sorted : if mid is greater than low or equal to
            if(nums[mid]>=nums[l]){
                // if the target is between left and mid , left included then we need to search in this subarray
                if(nums[l]<=target && target<nums[mid]) r = mid-1;
                else l = mid+1;
            }
            //right half is sorted : if mid is mid is smaller than high
            else{
                // if target is between the mid and right , right included , then we need to search in this subarray
                if(nums[mid]<target && target<=nums[r]) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
        
    }
};
int main()
{
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = s.search(nums, target);
    cout << result << endl;
    return 0;
}
