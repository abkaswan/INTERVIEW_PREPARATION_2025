#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Time complexity: O(2^n)
// space complexity: O(2^n) --> O(n) for recursion stack + O(2^n) for storing all subsets
class Solution {
  public:
    void subsum(vector<int>& arr,vector<int>& res,int sum,int i){
        // either select the current element or don't 
       if(i>=arr.size()){ 
            res.push_back(sum);
            return;
        }
        subsum(arr,res,sum+arr[i],i+1);
        subsum(arr,res,sum,i+1);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> v;
        subsum(arr,v,0,0);
        
        return v;
    }
};
int main() {
    Solution s;
    vector<int> arr = {1, 2, 3};
    vector<int> result = s.subsetSums(arr);
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}