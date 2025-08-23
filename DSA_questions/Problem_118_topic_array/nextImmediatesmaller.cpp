#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        int l = 0,r = 1,n=arr.size();
        while(r<n){
            if(arr[l]>arr[r]) arr[l] = arr[r];
            else arr[l] = -1;
            l++;
            r++;
        }
        arr[n-1] = -1;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {4, 2, 5, 1, 3};
    sol.immediateSmaller(arr);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}