#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int count = 0,maxcount = 0;
        for(char c : s)
        {
            if(c=='('){
                count+=1;
            }
            else if(c==')')
            {
                count-=1;
            }
            maxcount = max(count,maxcount);
        }
        return maxcount;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    // Read an entire line (including spaces) if needed; else use cin >> s;
    getline(cin, s);
    
    Solution sol;
    int depth = sol.maxDepth(s);
    cout << depth << "\n";
    
    return 0;
}