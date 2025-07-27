#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(logn)
// space complexity : O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r){
            int mid = l+(r-l)/2;
            // make mid a even index, do mid-- only;
            // why because : Off‑by‑one / out‑of‑bounds risk-->Imagine your window is [lo=5 … hi=6].You compute mid = (5+6)/2 = 5 (odd).You do mid++ → 6. Then you check arr[mid] vs. arr[mid+1] → that’s arr[6] vs. arr[7]… but index 7 is past your current hi. You’ve just read off the end of the active window (and maybe even off the end of the array).
            if(mid%2==1) mid--;
            // below conditions : this means that the single number will be in right half because the even index has it's correct double element.
            if(nums[mid]==nums[mid+1])
                l = mid+2;
            else
                r = mid;
        }
        // 1,1,2,3,3,4,4,8,8
        // l = 0, r = 8 , m = 4 -> r = 4
        // l =0 , r=4 , m = 2 -> r = 2
        // l = 0, r =2 , m = 0 -> l = 2
        // l==r break
        return nums[l];
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int result = sol.singleNonDuplicate(nums);
    cout << "The single non-duplicate element is: " << result << endl;
    return 0;
}