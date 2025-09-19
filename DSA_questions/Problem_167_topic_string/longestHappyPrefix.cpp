#include <iostream>
#include <vector>
#include <string>
using namespace std;
// time complexity : O(n) , space complexity : O(n)
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n,0);
        int len = 0, i = 1;
        while(i<n){
            if(s[i]==s[len]){
                lps[i]=len+1;
                i++;len++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return s.substr(0, lps[n - 1]);
    }
};
int main() {
    Solution sol;
    string s = "level";
    cout << "Longest happy prefix of \"" << s << "\" is: \"" << sol.longestPrefix(s) << "\"" << endl;
    return 0;
}