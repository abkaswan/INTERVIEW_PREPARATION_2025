#include <iostream>
#include <string>
using namespace std;
// time complexity : O(n*m) , space complexity : O(1) , fails at examples like aaaaaaab and aaaab it takes almost O(n*m) right

class Solution {
public:
    int strStr(string haystack, string needle) {
        // brute force : take one pointer for haystack and one for needle and match
        int n = haystack.size(), m = needle.size();
        if(m==0) return 0;// edge case

        for(int i = 0;i<=n-m;i++){
            int j = 0;
            while(j<m && haystack[i+j]==needle[j]){
                j++;
            }
            if(j==m) return i; // found match
        }
        return -1;
    }
};
int main() {
    Solution sol;
    string haystack = "hello";
    string needle = "ll";
    int index = sol.strStr(haystack, needle);
    cout << "Index of first occurrence: " << index << endl; // Output: 2
    return 0;
}