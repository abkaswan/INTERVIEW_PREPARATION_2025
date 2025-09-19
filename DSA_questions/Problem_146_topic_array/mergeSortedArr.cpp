#include <iostream>
#include <vector>
using namespace std;
// time complexity O(m+n)
// space complexity O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // last valid for the array1
        int i = m-1;
        // actual last for the array1
        int k = n+m-1;
        // actual last for the array2
        int j = n-1;

        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }
        // for the remaining elements copy them
        while(j>=0){
            nums1[k--] = nums2[j--];
         }


    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    sol.merge(nums1, m, nums2, n);
    for(int num : nums1) {
        cout << num << " ";
    }
    return 0;
}