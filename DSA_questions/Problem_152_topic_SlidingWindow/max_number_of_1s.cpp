#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity O(n) and space complexity O(1)
class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // sliding window keep window till we have hit the k 0s otherwise shrink it
        int n = arr.size();
        int maxlen = 0 , l = 0, r=0,count=0;
        while(r<n){
            if(arr[r]==0) count++;
            while(count>k){
                if(arr[l]==0) count--;
                l++;
            }
            
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 0, 1, 1, 0};
    int k = 1;
    cout << sol.maxOnes(arr, k) << endl;  // Output: 4
    return 0;
}