#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time complexity: O(n * 2^n) where n is the number of elements in nums.
// Space complexity: O(n * 2^n) for storing all subsets.
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res={{}};
        int start,x;
        for(int i = 0;i<nums.size();i++){
            start = 0;
            //now we will check if there are duplicates if yes then skip those
            if(i>0 && nums[i]==nums[i-1]) start=x;
            x = res.size();
            for(int j=start;j<x;j++){
                auto tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(move(tmp));
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);
    
    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}