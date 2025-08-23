#include <iostream>
#include <vector>
using namespace std;
// time complexity O(nlogn) and space complexity O(1)
// note : you can put nums[mid]>=nums[mid+1] as well , it will work fine
class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        // peak element : always compare with the left neighbour or right neighbour , you will always be guarantted to find the peak , if it goes till the boundary then that is your answer right ? think about it
        // O(nlong) time complexity and O(1) space

        // for this one simple trick is imagine the graph and go with the slop
        int n = nums.size();
        int l = 0, r = n-1;
        // let;s go with comparing with the right neighbour , but in this case you need to take the lower mid by l+r/2 because we are comparing with mid+1 so we need it available all the time
        while(l<r){
            // upper mid
            int mid = l+(r-l)/2;
            // this means either the mid is the answer or in the right side the answer is ?
            if(nums[mid]>nums[mid+1]) r = mid;
            else l = mid+1;
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