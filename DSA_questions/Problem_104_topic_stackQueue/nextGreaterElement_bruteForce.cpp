#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n1*n2 + n2^2 + n1).
// space complexity : O(1) as we are not using any extra space except for the input arrays.
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // my method : brute force 

        int n1 = nums1.size();
        int n2 = nums2.size();

        // mark nums1 array with indexes that we need to search
        for(int i = 0;i<n1;i++){
            for(int j = 0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    nums1[i] = j;
                    break;
                }
            }
        }
        // mark nums2 with the calculation 
        for(int i = 0;i<n2;i++){
            int x = nums2[i];
            for(int j = i;j<n2;j++){
                if(nums2[i]<nums2[j]){
                    nums2[i] = nums2[j];
                    break;
                }
            }
            // means it didnot change and did not find greater element
            if(x==nums2[i]) 
                nums2[i] = -1;
        }

        // now just get the answer using nums2 indexes in nums1 and fill them in nums1
        for(int i = 0;i<n1;i++){
            nums1[i] = nums2[nums1[i]];
        }

        return nums1;
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}