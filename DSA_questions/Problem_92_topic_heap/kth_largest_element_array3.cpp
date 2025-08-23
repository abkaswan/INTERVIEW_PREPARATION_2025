#include <iostream>
#include <vector>
using namespace std;
// each element is compared to a pivot only until it either wins (goes left) or loses (goes right), and once it’s moved past a pivot it never participates in future partitions. Summing over all nn elements gives a constant number of comparisons per element on average, i.e. Θ(n) total.
// time complexity : O(n) on average, O(n^2) in the worst case, space complexity : O(1)

class Solution {
public:
    // solution 3 : use quickselect algorithm to solve it 
    // quickselect review : 1. selection algo 2. can find top kth element in unsorted dataset 3. top can mean smallest or largest both 4. related to quick sort sorting algo so part of the quick select(partitioning mostly) will be similar to quick sort
    // quicksort algo ---> pivot : arbitrary element in the array (could be 3,1,4 or 2) for arr : [3,1,4,2], partition : two separate halfs around our pivot , left half smaller than pivot , right greater than pivot , base case for quick sort algo when our subset of data is of size 1
    // quickselect algo ---> selecting a pivot and partitiong is the same , but quick select is not a divide and conquer algo , although quick select runs the paritioning algo only on the side that contains the top kth ele
    // so knowing what index our answer would be is vital for this algo 
    // [3,1,4,2] the 3rd largest element would be on index 1 right ? same way
    // once our pivot becomes 1 we know we would have found our 3rd largest element right in this unsorted array? think about it


    // time compleixty : O(n)  -- O(n²) when your pivot choice is always “bad” (e.g. picking the last element on an already sorted or nearly-sorted array , space complexity : O(1)
    int partition(int left, int right, int pivot,int n,vector<int>&nums){
        //compare with the pivot
        int i = left,j = left;
        int pivotValue = nums[pivot];
        // swap the pivot with the right index so it doesn't interfere with our result
        swap(nums[right],nums[pivot]);

        while(j<right){
            if(nums[j]<pivotValue){
                swap(nums[i++],nums[j]);
            }
            j++;
        }
        // now move pivot to its right place 
        swap(nums[i],nums[right]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0,right = n-1;

        // for kth largest elememt the index would be : n-k right
        int target = n-k;


        while(left<=right){
            // picking the last element as pivot -- but it gives O(n^2) in already sorted array so didnt' use it
            // int pivot = right;
            // random pivot
            int pivot = left + rand() % (right - left + 1);
            
            int pos = partition(left,right,pivot,n,nums);
            if(pos==target){
                // found the kth largest
                return nums[pos];
            }
            // pivot is on left , focus on right subarray
            if(pos<target){
                left = pos+1;
            }
            //pivot is on right , focus on left subarray
            else{
                right = pos-1;
            }
        }
        return -1;
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