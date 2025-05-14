#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // need to think , when to move right and when to move left
        map<char,int>mpp;
        int l = 0, r = 0, n = s.size(),maxLen=0,maxFreq;
        while(r<n){
            mpp[s[r]]++; // saving the freq for those two characters;
            // got the question wrong only : we can take any number of characters and change them but we can do it atmost k times only , now think about it.
            // You need to figure out, for this window, what is the minimum number of characters you'd need to change to make all characters in s[l...r] identical. If that minimum number of changes is more than k, then the window is invalid, and you must shrink it from the left.
            // that means the window length r-l+1 and the biggest char freq , if we minus with it if that is more than k we need to shrink the window because then we can't replace all those character something would be left
            maxFreq = max(maxFreq,mpp[s[r]]);
            while((r-l+1)-(maxFreq)>k) 
            {
                mpp[s[l]]--;
                l++; //here we shift the left pointer
            }
            maxLen = max(maxLen,r-l+1); // our result we are getting the length for that
            r++; // increasing the right pointer
        }
        return maxLen; //return the result
    }
};
int main() {
    Solution solution;
    string s = "AABABBA";
    int k = 1;
    int result = solution.characterReplacement(s, k);
    cout<<result<<endl;
    return 0;
}