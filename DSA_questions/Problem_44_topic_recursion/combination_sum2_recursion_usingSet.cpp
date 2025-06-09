#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
class Solution {
public:
    // int is enough as the length is 100 and max ele in c can be 50 so 50000 which int will cover
    void fun(vector<int>& c, int t,set<vector<int>>& res,vector<int>& v,int i,int sum){
        // base case
        if(i>c.size() || sum>=t)
        {
            if(sum==t) res.insert(v);
            return;
        }
        //each number in c can be used once only so we need to move forward in either choices
        // include the current element
        v.push_back(c[i]);
        fun(c,t,res,v,i+1,c[i]+sum);
        //backtrack 
        v.pop_back();
        //exclude the current element
        fun(c,t,res,v,i+1,sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> resi;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        fun(candidates,target,resi,v,0,0);
        vector<vector<int>> res;
        
        //extract from set resi and put it in vector res
        for(auto it=resi.begin();it!=resi.end();it++){
            res.push_back(*it);
        }
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
