#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time complexity : You make two recursive calls at each of the n levels → 2^n leaves. At each leaf, you do res.push_back(v), which copies up to n elements.
// So total work ≃ ∑𝑘=0𝑛((𝑛𝑘)×𝑘)  =  𝑛 2𝑛−1  =  𝑂(𝑛 2𝑛).
// Time: O(n.2^n)

// Space: O(n) for the recursion stack and you store every subset of average length ≃ n/2, so total space ∑𝑘=0𝑛((𝑛𝑘)×𝑘)=𝑂(𝑛.2^𝑛)

class Solution {
public:
    void subset(vector<int>& nums,int i,vector<vector<int>>& res,vector<int>& v,bool prevtaken){
        if(i>=nums.size())
        {
            res.push_back(v);
            return;
        }

        // so if we are going to take any of the new number then we need to make sure 
        // -- if they are both different then take it 
        // --  if they are same then we check if previous element was taken , in that case we approve and in the other one we don't 

        if(i==0 || nums[i]!=nums[i-1] || prevtaken)
        {
            v.push_back(nums[i]);
            subset(nums,i+1,res,v,true);
            v.pop_back();
        }
        subset(nums,i+1,res,v,false);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        sort(nums.begin(),nums.end());
        subset(nums,0,res,v,false);
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