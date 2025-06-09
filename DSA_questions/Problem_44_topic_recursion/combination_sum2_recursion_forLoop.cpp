#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
class Solution {
public:
    void fun(vector<int>& c, int t,vector<vector<int>>& res,vector<int>& v,int i,int sum){
        // base case
        if(sum==t){
            res.push_back(v);
            return;
        }
        // here each time we take some of the decision like at the 0th index should we take 1st , 2nd etc etc elements , we skip it if it's duplicate , otherwise we take
        for(int j = i;j<c.size();j++){
            // to avoid duplicates
            if(j>i && c[j]==c[j-1]) continue; 
            //we just skip the whole subtree if this is the case because it is already sorted and the next elements will give the same results so , prune
            if(sum>t) break; 
            v.push_back(c[j]);
            fun(c,t,res,v,j+1,sum+c[j]);
            //backtrack
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        fun(candidates,target,res,v,0,0);
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(nums, target);

    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
