#include <iostream>
#include <vector>
using namespace std;
// time complexity: O(k * C(9,k)) = at each step we have two choices,include or exclude the current element , we do it for 1 to 9 so 2^9 = 512 recursive calls , more tightly it goes as deep as k numbers so the total number of valid root to leaf paths is C(9,k) which is 9!/(k!(9-k)!) and each path takes O(k) time to copy the vector to the result so total is O(k * C(9,k)) which is similar to O(1) 
// space complexity: O(k) for the recursion stack and O(k * C(9,k)) for the result vector
class Solution {
public:
    void fn(int i,int j, int sum,int k,int n,vector<int>& v,vector<vector<int>>& res)
    {
        if(j==k){
            if(sum==n) res.push_back(v);
            return;
        }
        if(sum>n || i>9) return;
        // include the current element
        v.push_back(i);
        sum+=i;
        fn(i+1,j+1,sum,k,n,v,res);
        //exclude the current element
        v.pop_back();
        sum-=i;
        fn(i+1,j,sum,k,n,v,res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> v;
        fn(1,0,0,k,n,v,res);
        return res;
    }
};
int main() {
    Solution sol;
    int k = 3, n = 7;
    vector<vector<int>> result = sol.combinationSum3(k, n);
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}