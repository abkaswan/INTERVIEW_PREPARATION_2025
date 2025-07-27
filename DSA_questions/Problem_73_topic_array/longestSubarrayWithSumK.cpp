#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// time complexity : O(n)
// space complexity : O(n)
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // use the same method as : count subarray with sum k
        // there was hashMap of prefixSum with freq , here we will store first time the prefixAppeared then it's index
        unordered_map<int,int> mpp; 
        mpp[0] = -1; // in case prefixSum == k
        int n = arr.size(),maxLen=0,sum = 0; // here sum is prefixSum
        for(int i = 0;i<n;i++){
            sum+=arr[i];
            
            if(mpp.count(sum-k)) //then the index is there so add that
            {
                // for understanding writing it like this 
                int first = mpp[sum-k]+1;
                int last = i;
                maxLen = max(maxLen,last-first+1);
            }
            
            if(!mpp.count(sum)){
                mpp[sum]=i;
            }
        }
        return maxLen;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, -2, 5};
    int k = 5;
    int result = sol.longestSubarray(arr, k);
    // Output the result
    cout << "Length of longest subarray with sum " << k << ": " << result << endl;
    return 0;
}