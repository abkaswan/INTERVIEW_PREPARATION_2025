#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        
    }
};

int main() {
    Solution sol;
    vector<int> arr = {100, 140, 150, 200};
    vector<int> dep = {110, 300, 220, 230};
    cout << sol.findPlatform(arr, dep) << endl;  // Output: 3
    return 0;
}
