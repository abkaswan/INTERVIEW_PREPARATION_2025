#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Time : O(n²) — optimal for most practical use cases. --> O(n log n) + O(n²) = O(n²) nlogn is for sorting
// Space : O(log n) auxiliary (or O(1) if sorting in place), but O(n²) overall when counting result storage.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            int l=i+1,r=n-1;
            if(i>0 && nums[i]==nums[i-1]) continue; // skipping duplicates
            while(l<r){
                int sum = nums[l]+nums[r]+nums[i];

                if(sum==0){
                    v.push_back({nums[l],nums[i],nums[r]});

                    while(l<r && nums[l]==nums[l+1]) l++; // skipping duplicates
                    while(l<r && nums[r]==nums[r-1]) r--; // skipping duplicates
                    l++;
                    r--;
                }
                else if(sum<0)l++;
                else r--;
            }
        }
        return v;        
    }
};
int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);
    
    for (const auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}