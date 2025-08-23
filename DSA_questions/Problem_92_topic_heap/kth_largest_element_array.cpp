#include <iostream>
#include <vector>
using namespace std;
// This code finds the kth largest element in an array using a max heap approach.
// time complexity: O(n + k log n)
// space complexity: O(1) since we are modifying the input array in place.
class Solution {
public:
    void heapify(int i,vector<int>&nums,int n){
        while(i<n){
            int left = 2*i+1;
            int right = 2*i+2;
            int largest = i;
            if(left<n && nums[left]>nums[largest]) largest = left;
            if(right<n && nums[right]>nums[largest]) largest = right;
            if(i!=largest){
                swap(nums[i],nums[largest]);
                i = largest;
            }
            else{
                break;
            }
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // heapify the array for max-heap -- O(n) time
        for(int i = n/2-1;i>=0;i--){
            heapify(i,nums,n);
        }
        int res;
        // now we know how to delete from max heap follow that -- O(klogk)
        for(int i = 0;i<k;i++){
            // nums[0] is the top element - swap it with the last one and heapify again
            swap(nums[0],nums[n-1]);
            --n;
            heapify(0,nums,n);
        }
        // return the result
        return nums[n];

    }
};
int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = sol.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl; // Output: 5
    return 0;
}