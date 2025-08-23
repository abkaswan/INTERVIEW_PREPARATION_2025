#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        return {1};
    }
};
int main() {
    Solution sol;
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = sol.farMin(arr);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}