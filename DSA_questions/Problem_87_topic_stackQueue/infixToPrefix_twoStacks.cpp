#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


// Time Complexity:O(n) --Each character/token is processed once, and every operator or operand is pushed/popped at most once. Stack operations (push, pop) are O(1), so the entire algorithm runs in linear time
// Space Complexity:O(n)
// You maintain two stacks:
//     Operators stack size is O(n) in worst case,
//     Operands stack also may build up intermediate strings of total length O(n).
// So overall auxiliary space is linear in the input length

// yes, like postfix, prefix expressions can have different valid strings — but they always represent the same underlying structure. --- just try to draw there tree and if it's same then no worry it;s fine.
// for this one we are taking in account the right associativity of ^
class Solution {
  public:
  bool isRightAssoc(char op) {
        // '^' is the only right‑associative operator here
        return op == '^';
    }
    int precedence(char c){
        if(c == '^') return 3;
        if(c == '*' || c == '/') return 2;
        if(c == '+' || c == '-') return 1;
        return 0;
        
    }
    string infixToPrefix(string& s) {
        stack<string> s1; //store operands or the strings that will give us the results
        stack<char> s2;// store operators based on the precedence
        //use the original string as output buffer instead of taking a new one
        int n = s.size(),i=0;
        // string res;
        
        
        for(char c: s){
            if(c==' ') continue;
            else if(isalpha(c) || isdigit(c)){
                //push it to the stack s1
                s1.push(string(1,c));
            }
            else if(c=='('){
                s2.push(c);
            }
            else if(c==')'){
                while(!s2.empty() && s2.top()!='('){
                    string right=s1.top();s1.pop();
                    string left=s1.top();s1.pop();
                    char op = s2.top();s2.pop();
                    // concatente all of them 
                    string combined = string(1,op)+left+right;
                    s1.push(combined);
                }
                if(!s2.empty() && s2.top()=='('){
                    s2.pop();
                }
            }
            else{ // +,-,*,/,^
                // operator so push in stack basend on precendence
                // pop higher/equal precendence from stack and push current
                while(!s2.empty() && (precedence(s2.top())>=precedence(c) || (!isRightAssoc(c) && precedence(s2.top()) == precedence(c)))) {
                    // need to perform OpLeftRight to get the correct order
                    string right=s1.top();s1.pop();
                    string left=s1.top();s1.pop();
                    char op = s2.top();s2.pop();
                    // concatente all of them 
                    string combined = string(1,op)+left+right;
                    s1.push(combined);
                    
                }
                s2.push(c);   
            }
            
        }
        // if something left process them also 
        while(!s2.empty()){
            string right=s1.top();s1.pop();
            string left=s1.top();s1.pop();
            char op = s2.top();s2.pop();
            // concatente all of them 
            string combined = string(1,op)+left+right;
            s1.push(combined);
        }
        return s1.empty() ? "" : s1.top();
        
    }
};

int main() {
    Solution sol;
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    
    
    string prefix = sol.infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;
    return 0;
}