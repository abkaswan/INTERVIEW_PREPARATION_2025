#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

// time complexity: O(n)
// space complexity: O(1) (in-place modification of the string)

class Solution {
public:
    string reverseWords(string s) {
        // two pointers and do it
        int n = s.size();
        // reverse the whole string -- O(n)
        reverse(s.begin(),s.end());
        
        // now remove whitespaces and reverse each word -- O(n)
        int l=0,r=0;
        int i = 0;
        while(i<n)
        {
            while(i<n && s[i]==' ') i++; // skip spaces at most O(n)
            if(i==n) break;
            while(i<n && s[i]!=' '){ // copy character - at most O(n)
                s[r++] = s[i++];
            }
            reverse(s.begin()+l,s.begin()+r); // reverse the word -- O(word length) = O(n) worst case
            s[r++]=' ';
            l = r;
            i++;
        }
        //resize the string in the last step and return -- O(n) worst case , O(1) amortized C++
        s.resize(r-1);
        return s;

    }
};
int main() {
    Solution sol;
    string s = "  hello world  ";
    cout << sol.reverseWords(s) << endl; // Output: "world hello"
    return 0;
}