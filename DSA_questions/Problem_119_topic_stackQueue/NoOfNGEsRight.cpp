#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// Time Complexity: O(m * n)
// Space Complexity: O(m)
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // here instead of next greater element we need to give overall greater elements count interesting!
        
        int n = arr.size(),m = indices.size();
        
        vector<int> v(m,0);
        
        
        
        int count = m-1;
        // start from index ind to the last n
        for(int i = 0;i<m;i++){
            int ind = indices[i];
            int cnt = 0;
            for(int i = ind+1;i<n;i++){
                if(arr[i]>arr[ind]) ++cnt;
            }
            v[i] = cnt;
        }
        
        
        
        return v;
    
    }
};
int main() {
    Solution sol;
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> indices = {0, 1, 2, 3, 4};
    vector<int> result = sol.count_NGE(arr, indices);
    
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}