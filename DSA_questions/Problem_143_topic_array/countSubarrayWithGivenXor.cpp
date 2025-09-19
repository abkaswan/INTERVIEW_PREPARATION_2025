#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// time complexity: O(n)
// space complexity: O(n)

// explantion: so for xor the properties are    1. a^b^b = a 2. a^0 = a 3. a^a = 0
// so we can use these properties to find the subarrays with given xor
// prefixSumxor => xor of all elements from 0 to i
// now if we have prefixSumxor from 0 to i and prefixSumxor from 0 to j then if we do prefixSumxor(0 to i) ^ prefixSumxor(0 to j) = prefixSumxor(i+1 to j) right
// so if we want prefixSumxor(i+1 to j) = k then prefixSumxor(0 to i) ^ prefixSumxor(0 to j) = k => prefixSumxor(0 to i) = k ^ prefixSumxor(0 to j)
// so if we have prefixSumxor(0 to j) and k then we can find prefixSumxor(0 to i) right and if we have that in our map then we can say that there exists a subarray with given xor

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1; // for when the prefixSumxor^k = 0 right that means this itself is the subarray from 0 to whatever prefixSumxor was for 
        long count = 0;
        int n = arr.size(), prefixSumxor = 0;
        for(int i = 0;i<n;i++){
            
            prefixSumxor = prefixSumxor^arr[i];
            
            // check if we have seen it before
            if(mpp.find(prefixSumxor^k)!=mpp.end()) count+=mpp[prefixSumxor^k];
            
            // store current prefix sum xor
            mpp[prefixSumxor]+=1;
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    long result = sol.subarrayXor(arr, k);
    cout << "Count of subarrays with given XOR: " << result << endl; // Output: 4
    return 0;
}