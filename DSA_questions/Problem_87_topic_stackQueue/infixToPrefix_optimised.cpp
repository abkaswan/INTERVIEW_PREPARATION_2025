#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
// time complexity: O(n) ==> First reverse: O(n),Bracket conversion loop: O(n),Postfix conversion: O(n),Final reverse: O(n) --- Total: O(n + n + n + n) = O(n)
// space complexity: O(n) for stack

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
    string infixToPostfix(string& s) {
        stack<char> st; //store operators based on the precendence
        
        //use the original string as output buffer instead of taking a new one
        int n = s.size(),i=0;
        // string res;
        
        
        for(char c: s){
            if(c==' ') continue;
            else if(isalpha(c) || isdigit(c)){
                // res+=c;
                s[i++]=c;
            }
            else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
                // operator so push in stack basend on precendence
                // pop higher/equal precendence from stack and push current
                while(!st.empty() && (precedence(st.top())>precedence(c) || (!isRightAssoc(c) && precedence(st.top()) == precedence(c)))) {
                    // res+=st.top();
                    s[i++]=st.top();
                    st.pop();
                }
                st.push(c);   
            }
            else if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    // res+=st.top();
                    s[i++]=st.top();
                    st.pop();
                }
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
            }
        }
        //pop the remaning 
        while(!st.empty()){
            // res+=st.top();
            s[i++]=st.top();
            st.pop();
        }
        // now resize the string s till this index
        s.resize(i);
        // return res;
        return s;
        
        
    }
};

int main() {
    Solution sol;
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    
    // step 1 : first of all reverse the string while ( to ) and ) to ( also to maintain order
    reverse(infix.begin(),infix.end());
    for(char& c:infix)
    {
        if(c=='(') c=')';
        else if(c==')') c='(';
    }
    // step 2 : do the postfix for that string
    string postfix = sol.infixToPostfix(infix);
    //step 3 : reverse the string now because that's your answer
    reverse(postfix.begin(),postfix.end());
    cout << "Prefix: " << postfix << endl;
    return 0;
}