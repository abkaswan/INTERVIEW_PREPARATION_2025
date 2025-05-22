#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // top down : memoization approach 
    // as the count can't be more than s.size() right and index also so took the dp for that size . now time complexity would be n^2 and space compleixty :aux space for memoization and stack space for recursion : o(n^2)+o(n) ==> O(n^2)
    bool check(string s,int i,int count,vector<vector<int>>& v){
        
        if (count < 0) return false;
        if(i==s.size()) return count==0;

        // look up if is available for vector 
        if(v[i][count]!=-1) return v[i][count];
        bool ans = false;

        if(s[i]=='(')
            ans = check(s,i+1,count+1,v);
        else if(s[i]==')')
            ans = check(s,i+1,count-1,v);
        else
        {
            ans = check(s,i+1,count+1,v) || check(s,i+1,count,v) || check(s,i+1,count-1,v);
        }
        // if answer is not stored then store it 
        v[i][count] = ans?1:0;
        return ans;
    }
    bool checkValidString(string s) {
        // let's solve it using recursion so that we can use it during DP. 
        int n=s.size();
        vector<vector<int>> v(n,vector<int>(n,-1));
        return check(s,0,0,v);
    }
};
int main() {
    Solution sol;
    string s;
    cin >> s;
    bool result = sol.checkValidString(s);
    cout << result << endl;
    return 0;
}
