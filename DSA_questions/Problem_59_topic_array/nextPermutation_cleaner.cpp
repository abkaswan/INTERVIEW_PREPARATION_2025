#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // my own method -- tweaked to look clean
        int n = nums.size();
        // step 1 : find the pivot (first drop from the end)
        int pivot = n-2;
        while(pivot>=0 && nums[pivot]>=nums[pivot+1]){
            pivot--;
        }
        if(pivot>=0){
            // step 2 : find the rightmost successor to pivot
            int successor=n-1;
            while(nums[successor]<=nums[pivot])
                --successor;
            swap(nums[pivot],nums[successor]);
        }
        reverse(nums.begin()+pivot+1,nums.end());
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    s.nextPermutation(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}