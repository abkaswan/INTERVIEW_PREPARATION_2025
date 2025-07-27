#include <iostream>
#include <vector>
using namespace std;
// time complexity: O(n)
// space complexity: O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // here instead of the usual neg+pos method where we use hashmap and prefix we can simply use two pointers that will save us extra O(n) space here
    int n = a.size();
    int l = 0, r = 0,maxLen = 0;
    long long sum = 0;
    while(r<n){
        sum+=a[r];
        while(l<=r && sum>k){
            sum-=a[l++];
        }
        if(sum==k){
            maxLen = max(maxLen,r-l+1);
        }
        r++;
    }
    return maxLen;
}
int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    long long k = 9;
    int result = longestSubarrayWithSumK(a, k);
    cout << "Length of longest subarray with sum " << k << ": " << result << endl;
    return 0;
}