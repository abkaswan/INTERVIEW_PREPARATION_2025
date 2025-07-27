#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Time complexity: O(2^n)
// space complexity: O(2^n) --> O(2^n) for storing all subsets
class Solution {
  public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> v;
        v.push_back(0); // start with the empty subset sum
        for(auto i: arr){
            int n = v.size();
            for(int j = 0;j<n;j++){
                v.push_back(v[j]+i);
            }
        }    
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