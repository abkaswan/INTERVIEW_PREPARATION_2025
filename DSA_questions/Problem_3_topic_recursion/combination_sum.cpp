#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void fun(vector<int>& candidates,int target,int i,int sum,vector<int>& v,vector<vector<int>>& res){
            //base condition ; only if sum >= target , not when i == nums.size() because there is no limit this time.
            // also if i goes out of bound return it 
            if(i>=candidates.size() || sum>=target){
                if(sum==target){
                    res.push_back(v);
                }
                return;
            }
    
            //add the element everytime right
            v.push_back(candidates[i]);
            //include the element
            fun(candidates,target,i,sum+candidates[i],v,res);
            //pop back the element here after backtracking
            v.pop_back();
            //exclude the element
            fun(candidates,target,i+1,sum,v,res);
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> res;
            vector<int> v;
            fun(candidates,target,0,0,v,res);
            return res;
        }
};

int main() {
    Solution sol;

    // Example input
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    // Call combinationSum
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    // Print result
    cout << "Combinations that sum up to " << target << ":\n";
    for (const auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}