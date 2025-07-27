#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity: O(n) : O(n) for traversal from end to start and O(n) for reversing the vector
// space complexity: O(n)
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> v;
        v.push_back(arr[n-1]);
        for(int i = n-2;i>=0;i--){
            if(arr[i]>=v.back())
                v.push_back(arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};
int main() {
    Solution sol;
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = sol.leaders(arr);
    cout << "Leaders in the array are: ";
    for (int leader : leaders) {
        cout << leader << " ";
    }
    cout << endl;
    return 0;
}