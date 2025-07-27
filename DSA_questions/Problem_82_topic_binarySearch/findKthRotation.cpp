#include <iostream>
#include <vector>
using namespace std;
// time complexity is O(log n) and space complexity is O(1)
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // ok need to find how many times rotated so find the element which separates two sorted arrays
        // it is mentioned integers are distinct
        int n = arr.size();
        int l=0,h=n-1;
        if(arr[l]<arr[h]) return 0;
        while(l<h){
            int m = l+(h-l)/2;
            //compare with high 
            if(arr[h]>arr[m]){
                // so it's between l and m could be m also.
                h = m;
            }
            else{
                // otherwise it is in between m+1 and h.
                l = m+1;
            }
        }
        return l;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int k = sol.findKRotation(arr);
    cout << "The array is rotated " << k << " times." << endl;
    return 0;
}