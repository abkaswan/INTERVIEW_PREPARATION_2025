#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // using recursion approach : just trying it out so i can use this when i am doing dp. otherwise tc : O(3^n) and sc : O(n) are not at all ideal.
    bool check(string s,int i,int count){
        if (count < 0) return false; // pruning branches early 
        if(i==s.size()) return count==0;
        if(s[i]=='(')
            return check(s,i+1,count+1);
        else if(s[i]==')')
            return check(s,i+1,count-1);
        else
        {
            return check(s,i+1,count+1) || check(s,i+1,count) || check(s,i+1,count-1);
        }
    }
    bool checkValidString(string s) {
        // let's solve it using recursion so that we can use it during DP. 
        return check(s,0,0);
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
