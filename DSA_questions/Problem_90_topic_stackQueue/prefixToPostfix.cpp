#include <iostream>
#include <stack>
#include <string>
using namespace std;

// time complexity : O(n) because we traverse the expression once
// space complexity : O(n) because we use a stack to store the intermediate expressions
class Solution {
  public:
    string preToPost(string p) {
        // same as pre to Infix mostly -- just do (OP A B) to (A B OP)
        stack<string> s;
        int n = p.size();
        for(int i=n-1;i>=0;i--){
            if(isalnum(p[i])) s.push(string(1,p[i]));
            else{// if+,-,*,/,%,^
                string left = s.top();s.pop();
                string right = s.top();s.pop();
                char OP = p[i];
                string combined = left+right+string(1,OP);
                s.push(combined);
                
            }
        }
        return s.empty()?"":s.top();
    }
};
int main() {
    Solution sol;
    string prefix = "*-A/BC-/AKL";
    string postfix = sol.preToPost(prefix);
    cout << "Postfix: " << postfix << endl;
    return 0;
}