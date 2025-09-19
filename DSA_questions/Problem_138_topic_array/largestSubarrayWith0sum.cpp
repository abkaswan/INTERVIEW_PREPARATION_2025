#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// time complexity : O(n)
// space complexity : O(n)
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size(),maxLen = 0,prefixSum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = -1; // so that when prefixSum comes 0 we can tell that it started from index 0 right ?
        for(int i = 0;i<n;i++){
            prefixSum+=arr[i];
            if(mpp.find(prefixSum)==mpp.end()){
                mpp[prefixSum] = i;
            }
            else{
                int index = i-mpp[prefixSum];
                maxLen = max(maxLen,index);
            }
        }
        return maxLen;
        
    }
};
int main() {
    vector<int> arr = {1, -1, 3, 2, -2, 4};
    Solution sol;
    int result = sol.maxLength(arr);
    cout << "The length of the largest subarray with sum 0 is: " << result << endl;
    return 0;
}