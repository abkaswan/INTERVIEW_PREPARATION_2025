#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // my own method 
        // step 1 : find the starting point of the desending sorted sub array in nums
        int n = nums.size(),ind = -1,rep=n-1;
        for(int i = n-1;i>0;i--){
            if(nums[i-1]<nums[i])
            {
                ind = i;
                break;
            }    
            
        }
        // step 2: if ind is still -1 then the whole array is in descending order so in that case the reverse order of that will be answer 
        if(ind == -1) reverse(nums.begin(),nums.end());
        // otherwise , the index before ind-1 take that , find the nubmer just greater than that index's and replace both of them , now reverse the array from (ind,endOfArray)
        else{
            for(int i = ind;i<n;i++){
                if(nums[ind-1]>=nums[i]){
                    rep = i-1;
                    break;
                }
            }
            //swap both of them
            int temp = nums[ind-1];
            nums[ind-1] = nums[rep];
            nums[rep] = temp;
            
            reverse(nums.begin()+ind,nums.end());
        }
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