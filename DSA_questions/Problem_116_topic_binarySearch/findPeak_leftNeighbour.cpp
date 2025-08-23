#include <iostream>
#include <vector>
using namespace std;
// time complexity O(nlogn) and space complexity O(1)
// NOTE : you can put nums[mid]>=nums[mid-1] as well , it will work fine
class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        // peak element : always compare with the left neighbour or right neighbour , you will always be guarantted to find the peak , if it goes till the boundary then that is your answer right ? think about it

        // for this one simple trick is imagine the graph and go with the slop
        int n = nums.size();
        int l = 0, r = n-1;
        // let;s go with comparing with the left neighbour , but in this case you need to take the upper mid which happens by l+r+1/2 , if you take right neighbour it happens by l+r/2 the lower mid
        while(l<r){
            // upper mid
            int mid = l+(r-l)/2+1;
            // this means either the mid is the answer or in the right side the answer is ?
            if(nums[mid]>nums[mid-1]) l = mid;
            else r = mid-1;
        }
        return l; // or r both are same
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int peak = sol.findPeakElement(nums);
    cout << "Peak Element Index: " << peak << endl; // Output: 2
    return 0;
}