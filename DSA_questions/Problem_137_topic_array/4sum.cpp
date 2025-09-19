#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Time : O(n³) — optimal for most practical use cases. --> O(n log n) + O(n³) = O(n³) nlogn is for sorting
// Space : O(log n) auxiliary (or O(1) if sorting in place), but O(n³) overall when counting result storage.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> v;
        // sort the array
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            // return the duplicates
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1;j<n;j++){
                // return the duplicates
                if(j>i+1 && nums[j]==nums[j-1]) continue; 
                
                int l = j+1, r = n-1;
                while(l<r){
                    long long sum = (long long)nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target){
                        v.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1]) l++; // skipping duplicates
                        while(l<r && nums[r]==nums[r-1]) r--; // skipping duplicates

                        l++;r--;
                    }
                    else if(sum<target) l++;
                    else r--;
                }
            }
        }
        return v;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = sol.fourSum(nums, target);
    
    for (const auto& vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}