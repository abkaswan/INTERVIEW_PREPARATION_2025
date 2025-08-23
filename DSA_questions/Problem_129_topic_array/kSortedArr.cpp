#include <iostream>
#include <string>
using namespace std;
// Sorting: O(n log n)
// Building map: O(n)
// Checking: O(n)
// Time complexity : O(n log n), which is efficient.

// Space complexity: O(n)
class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        vector<int> sortedArr(arr,arr+n);
        sort(sortedArr.begin(),sortedArr.end());
        
        unordered_map<int,int> mpp; // since there can be duplicate elements 
        for(int i = 0;i<n;i++){
            mpp[sortedArr[i]] = i;
        }
        
        for(int i = 0;i<n;i++){
            int index = mpp[arr[i]];
            
            if(abs(index-i)>k){
                return "No";
            }
        }
        return "Yes";
    }
};
int main() {
    Solution sol;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    string result = sol.isKSortedArray(arr, n, k);
    cout << "Is the array k-sorted? " << result << endl;
    return 0;
}