#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        
    }
};
int main() {
    Solution sol;
    vector<int> arr = {3, 1, 5, 4, 2};
    int k = 2;
    sol.nearlySorted(arr, k);
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}