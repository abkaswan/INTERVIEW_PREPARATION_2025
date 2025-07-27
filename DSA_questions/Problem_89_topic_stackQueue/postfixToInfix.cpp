#include <iostream>
#include <stack>
#include <string>
using namespace std;
// time complexity : O(n) because we traverse the expression once
// space complexity : O(n) because we use a stack to store the intermediate expressions
class Solution {
  public:
    string postToInfix(string exp) {
        // postfix to infix : 
        // start from left to right , use stack to store the string expressions 
        // and whenever you encouter operator , pop left , pop right and do (left OP right) and again push in stack
        
        stack<string> s;
        for(char c : exp){
            if(isalnum(c)) s.push(string(1,c));
            else{//if +,-,*,/,%,^
                string right = s.top();s.pop();
                string left = s.top();s.pop();
                char OP = c;
                string combined = '('+left+string(1,OP)+right+')';
                s.push(combined);
            }
        }
        return s.empty()?"":s.top();
        
    }
};
int main() {
    Solution sol;
    string postfix = "AB+C*D-";
    string infix = sol.postToInfix(postfix);
    cout << "Infix: " << infix << endl;
    return 0;
}
