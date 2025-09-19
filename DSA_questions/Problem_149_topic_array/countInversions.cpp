#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // brute - force first O(n^2) time and O(1) space
        int n = arr.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(arr[i]>arr[j]) count+=1;
            }
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {2, 3, 8, 6, 1};
    cout << sol.inversionCount(arr) << endl; // Output: 5
    return 0;
}