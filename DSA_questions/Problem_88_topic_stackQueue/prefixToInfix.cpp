#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Time Complexity: O(n) ---> You iterate through the input string once (from right to left), processing each character exactly one time. On encountering an operand → push (O(1)).On encountering an operator → pop twice, concatenate, then push (all constant-time operations, amortized over the run).
// Since each token is processed just once and stack ops are constant time, total runtime is O(n)

// Space Complexity: O(n) --->  A stack is used to store intermediate expressions, which in the worst case may hold up to n elements. 

class Solution {
  public:
    string preToInfix(string p) {
        // prefix to infix --
        // hint : start from R-L and enter operands in the stack this time , 
        // when encoutering operator just do (A OP B) and push it back to the stack ,
        
        // TC : O(n) and SC : O(n)
        stack<string> s;
        int n = p.size();
        for(int i = n-1;i>=0;i--){
            if(p[i]==' ') continue;
            else if(isalpha(p[i]) || isdigit(p[i])){
                s.push(string(1,p[i]));
            }
            else{ // in case of *,-,/,*,%,^
                string left = s.top();
                s.pop();
                string right = s.top();
                s.pop();
                char OP = p[i];
                string combined = '('+left+string(1,OP)+right+')';
                s.push(combined);
            }
            
        }
        return s.empty()?"":s.top();
        
    }
};
int main() {
    Solution sol;
    string prefix = "*-A/BC-/AKL";
    string infix = sol.preToInfix(prefix);
    cout << "Infix: " << infix << endl;
    return 0;
}