#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //same question as rotated sorted array but this time not necessarily with distinct values
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target) return true;
            // from normal sorted circular array there is one diff , what if array is like this [1 0 1 1 1] or [4,0,1,2,3,4,4,4,4], in this using l,mid,r we can't tell if left half is sorted or right one using mid and l , or mid and r comparison , so shrink the window for that.
            if(nums[mid]==nums[l] && nums[mid]==nums[r])
            {
                l++;
                r--;
                continue;
            }
            
            //decide which array we need to go to l/r , based on that continue the search
            //left array is sorted so go there
            if(nums[mid]>=nums[l]){
                // check if it is between [left,mid) if yes then move right
                if(nums[l]<=target && target<nums[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            //else right array is sorted so go there
            else{
                //check if it is between (mid,right] if yes then move left
                if(nums[mid]<target && nums[r]>=target){
                    l = mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return false;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    bool result = sol.search(nums, target);
    cout << "Target " << target << (result ? " found" : " not found") << " in the array." << endl;
    
    target = 3;
    result = sol.search(nums, target);
    cout << "Target " << target << (result ? " found" : " not found") << " in the array." << endl;

    return 0;
}

