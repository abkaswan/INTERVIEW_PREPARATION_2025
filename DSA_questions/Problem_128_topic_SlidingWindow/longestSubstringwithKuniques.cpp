#include <iostream>
#include <unordered_map>
using namespace std;
// time complexity: O(n)
// space complexity: O(1) -- O(min(n, alphabet_size)) → effectively O(1) if alphabet is bounded (e.g., 26 or 256). you can use array of fixed size also instead of unordered map
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int l = 0, r = 0;
        int n = s.size(),res = 0;
        unordered_map<char,int> mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            res = max(res,r-l+1);
            r++;
        }
        if(mpp.size()<k) return -1;
        return res;
    }
};
int main() {
    Solution sol;
    string s = "aabbcc";
    int k = 2;
    int result = sol.longestKSubstr(s, k);
    cout << "Length of longest substring with " << k << " unique characters: " << result << endl; // Output: 4
    return 0;
}