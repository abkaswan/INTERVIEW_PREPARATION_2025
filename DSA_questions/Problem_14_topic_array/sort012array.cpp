#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // conditions : one pass solution , with O(1) space 
        // need to do in-place

        // m1: just use library functions for this sort(nums.begin(),nums.end())
        // m2: use merge or quick sort O(nlogn)
        // m3 : two pass counting sort : count 0s,1s,2s and then rewrite the array like that O(n) tc two passes ,O(1) sc
        // m4 ; std::stable partition Cascade or std::partition Cascade (this parititoin cascade does not preserve relative ordering)  -- O(n) tc two passes , O(1) sc
        // m3: use three pointers to solve this problem 
        int l = 0,m = 0,r = nums.size()-1;
        while(m<=r)
        {
            if(nums[m]==0)
            {
                //swap with the nums[l]
                swap(nums[l++],nums[m++]);
            }
            else if(nums[m]==1)
            {
                m++;
            }
            else if(nums[m]==2)
            {
                //swap right and left with each other
                swap(nums[m],nums[r--]);
            }
        }

    }
};
int main() {
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}
