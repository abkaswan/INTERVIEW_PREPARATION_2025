#include <iostream>
#include <stack>
#include <string>
using namespace std;
// time complexity: O(n)
// space complexity: O(n)
class Solution {
  public:
    string postToPre(string p) {
        // postfix to prefix : same as postfix to infix
        stack<string> s;
        for(char c : p)
        {
            if(isalnum(c)) s.push(string(1,c));
            else{ //if +,-,*,/,%,^ i.e. operatores
                string right = s.top();s.pop();
                string left = s.top();s.pop();
                string combined = string(1,c)+left+right;
                s.push(combined);
                
            }
        }
        return s.empty()?"":s.top();
    }
};
int main() {
    Solution sol;
    string postfix = "AB+C*D-";
    string prefix = sol.postToPre(postfix);
    cout << "Prefix: " << prefix << endl;
    return 0;
}
