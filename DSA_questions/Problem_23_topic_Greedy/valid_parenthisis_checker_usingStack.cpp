#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // using stack approach : using O(n) tc and O(n) sc for the two stack we are using
    bool checkValidString(string s) {
        // let's solve it using two stack also 
        stack<int> s1,s2;
        for(int i = 0;i<s.size();i++)
        {
            //enter ( in first stack .
            if(s[i]=='(')
                s1.push(i);
            // enter * in second stack.
            else if(s[i]=='*')
                s2.push(i);
            // if ) then we need to think about how to pull either ( or make * a (
            else
            {
                if(!s1.empty())
                    s1.pop();
                else if(!s2.empty())
                    s2.pop();
                else 
                    return false;
            }
            
        }
        //now we need to take care of ( that are left in s1
        while(!s1.empty() && !s2.empty())
        {
            if(s1.top()>s2.top()) //means we can't make * as ),even if you do it wouldbe wrong
                return false;
            s1.pop();
            s2.pop();
        }
        // if there is still something in stack1 then we did not satisfy all the ( so return false
        return s1.empty();
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
