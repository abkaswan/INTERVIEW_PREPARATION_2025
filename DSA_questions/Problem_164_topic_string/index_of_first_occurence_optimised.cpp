#include <iostream>
#include <string>
#include <vector>
using namespace std;
// time complexity : O(n+m) , space complexity : O(m) , where n is the size of haystack and m is the size of needle
class Solution {
public:
    void findLPS(vector<int>& lps, string s){
        int m = s.size();
        int len = 0,i = 1;
        // i is suffix pointer and len is prefix pointer

        while(i<m){
            // if they are matching simple just move forward both pointer and also put lps for that particular index
            if(s[len]==s[i]){
                lps[i] = len+1;
                i++;len++;
            }
            else{
                // if they are not matching means you will need to take the prefix pointer back to somewhere where we can resume the match ( it is not wise to put it back to starting point again otherwise it will always take O(n^2) to build this lps only) , so what we do is we try to find the point where we should move , for example for abcabdabcabc for this string at the last index , abcabd and abcabc was mathcing until it was mismatch on d!=c so now we move len to lps[len-1] which means the longest prefix suffix for the previous index where we can start the match again abcab this was the previous index right so for index of b what was the longest prefix suffix ab for this string , so we move to the c and then resume our match again
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    // just move forward with the suffix pointer
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        // optimised approach : use KMP algorithm for this

        int n = haystack.size(), m = needle.size();
        vector<int>lps(m,0);
        findLPS(lps,needle);
        // now start with our regular two string matching
        int first  = 0, second = 0;
        while(first<n && second<m){
            // if they are matching move forward
            if(haystack[first]==needle[second]){
                first++;
                second++;
            }
            else{
                // if not maching we need to move second to somewhere where we cna resume our search, if we move it back to 0 again and again then it will be O(n*m) in worst case but the lps array can be used here
                if(second!=0){
                    second = lps[second-1];
                }
                else{
                    first++;
                }
            }
        }
        if(second == m) return first-second;
        return -1;
    }
};
int main() {
    Solution sol;
    string haystack = "hello";
    string needle = "ll";
    int result = sol.strStr(haystack, needle);
    cout << "Index of first occurrence: " << result << endl; // Output: 2
    return 0;
}