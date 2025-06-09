#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// time complexity : O(logn)+O(logn) = O(2logn) we are doing which is not required == see optimised code in next file
// sc : O(1)
class Solution {
public:
    int bs(vector<int>&nums,int l,int r,int target){
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target) return m;
            else if(nums[m]<target) l=m+1;
            else r = m-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // find the pivot
        int l = 0,r=n-1;
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m]>nums[r]) l = m+1;
            // we do r=m becaue m might be min(pivot) element , so we don't want to exclude it
            else r=m;
        }
        
        int pivot = r;
        if(nums[pivot]<=target && target<=nums[n-1]){
            // go to right side sorted array
            return bs(nums,pivot,n-1,target);
        }
        else{
            //go to left side sorted array
            return bs(nums,0,pivot-1,target);
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
