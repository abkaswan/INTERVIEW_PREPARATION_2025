#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Time complexity : O(n) Space complexity : O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(st.empty()) return false;
                if(s[i]==')' && st.top()!='(') return false;
                if(s[i]=='}' && st.top()!='{') return false;
                if(s[i]==']' && st.top()!='[') return false;
                st.pop(); // we can pop now if till now we didnt return false, it is safe
            }
        }
        return st.empty();
    }
};
int main(){
    Solution s;
    cout << s.isValid("()") << endl; // 1
    cout << s.isValid("()[]{}") << endl; // 1
    cout << s.isValid("(]") << endl; // 0
    cout << s.isValid("([)]") << endl; // 0
    cout << s.isValid("{[]}") << endl; // 1
    return 0;
}
