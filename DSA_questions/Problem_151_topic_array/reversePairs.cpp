#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    long long count;
    Solution() : count(0) {}  // Initialize count in constructor
    void merge(int l,int mid, int r,vector<int>& nums){
        int low = l,high = mid+1;
        vector<int> temp;
        while(low<=mid && high<=r){
            if(nums[low]>nums[high]) temp.push_back(nums[high++]);
            else temp.push_back(nums[low++]);
        }
        while(low<=mid){
            temp.push_back(nums[low++]);
        }
        while(high<=r){
            temp.push_back(nums[high++]);
        }

        for(int i = l;i<=r;i++){
            nums[i] = temp[i-l];
        }
    }
    void mergeSort(int l,int r,vector<int>& nums){
        if(l>=r) return;
        int mid = l+(r-l)/2;
        mergeSort(l,mid,nums);
        mergeSort(mid+1,r,nums);

        // here you will do the comparison and get the count
        
        int low = l,high = mid+1;

        while(low<=mid && high<=r){
            // Need to use long long to handle potential overflow
            if(nums[low] > 2LL * nums[high]){
                count += (mid - low + 1);  // All elements from low to mid will form pairs
                high++;
            }
            else{
                low++;
            }
        }
        // can do like this also 
        // while(low<=mid){
        //     while(high<=r && nums[low]>2*nums[high]){
        //         high++;
        //     }
        //     count+=(high-mid-1);
        //     low++;
        // }

        // then do the normal merge
        merge(l,mid,r,nums);
    }
    int reversePairs(vector<int>& nums) {
        // m1 : use brute force , two for loops with O(n^2) tc and O(1) sc
        // m2 : use merge sort , O(nlogn) time and O(n) space -- it is exactly same as we were doing for couting inversions

        int n = nums.size();
        mergeSort(0,n-1,nums);
        return (int)count;

    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << sol.reversePairs(nums) << endl; // Output: 2
    return 0;
}
