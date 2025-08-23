#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        return {1};
        
    }
};
int main() {
    Solution sol;
    vector<vector<int>> arr = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    int K = arr.size();
    vector<int> result = sol.mergeKArrays(arr, K);
    
    cout << "Merged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}