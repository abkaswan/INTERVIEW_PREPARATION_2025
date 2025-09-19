#include <iostream>
#include <string>
using namespace std;
// time complexity O(n) and space complexity O(1)

// explanation :
// This solution works backward because the Delete operation only affects the most recent Append. 
//      If pat[i] matches tar[j], we greedily assume it was the final Append. 
//      If they don't match, the operation for pat[i] must have been a Delete, which necessarily cancels out the Append from its immediate predecessor, pat[i-1]. 
// Therefore, we can safely skip both characters (i -= 2) as a pair that had no net effect on the final string.

class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int n = pat.size(), m = tar.size();
        int i = n-1, j = m-1;
        
        // so need to do two operations take it or delete it 
        while(i>=0 && j>=0){
            if(pat[i]!=tar[j]){
                i-=2;
                
            }
            else{
                i--;
                j--;
            }
        }
        return j<0;
    }
};

int main() {
    Solution sol;
    string pat = "ab*c";
    string tar = "abc";
    bool result = sol.stringStack(pat, tar);
    cout << (result ? "Match" : "No Match") << endl;
    return 0;
}