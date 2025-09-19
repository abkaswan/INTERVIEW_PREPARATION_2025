#include <iostream>
#include <vector>
#include <string>
using namespace std;
// time complexity : O(n) , space complexity : O(n)
class Solution {
  public:
    int getLPSLength(string &s) {
        // method 1 : use lps array for this one 
        int len = 0, i = 1;
        int n = s.size();
        vector<int> lps(n,0);
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
        return lps[n-1];
        
    }
};
int main() {
    Solution sol;
    string s = "ababab";
    int result = sol.getLPSLength(s);
    cout << "Length of the longest prefix which is also suffix: " << result << endl; // Output: 4
    return 0;
}