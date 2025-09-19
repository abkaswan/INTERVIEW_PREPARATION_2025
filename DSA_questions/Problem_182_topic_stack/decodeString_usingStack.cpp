#include<iostream>
#include<stack>
#include<string>
using namespace std;
// Time Complexity: O(n + L)
//   - We traverse the input string once (O(n)).
//   - Each character in the decoded string is appended exactly once (O(L)).
//   - Since L ≤ 1e5 (given in constraints), overall complexity is O(n).
//
// Space Complexity: O(n + L)
//   - numStack and strStack can store at most O(n) elements in the worst case.
//   - The final decoded string requires O(L) space.
//   - So total space complexity is O(n + L).

class Solution {
  public:
    string decodedString(string &s) {
        // method 1 : use stack for this
        
        // step 1 : go to inner path of the string and see ( and do the operation till we encounter ) and do the same for inner -> outer ( 
        // curr : this just states what is the current string after the operations in the inner parts
        // strstack : this will have the strings that are still unprocessed till and inbetween [[ it will get reset to "" so that we have the actual strings
        // numstack : this will have the numbers that we need the repeatition with everytime we hit ] we will pop this and numstack and perform the operation
        stack<string> strstack;
        stack<int> numstack;
        string curr = "";
        for(int i = 0;i<s.size();i++){
            // while entering if encounter digit make full number and push it into another stack
            if(isdigit(s[i])){
                int num = 0;
                while(i<s.size() && isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                numstack.push(num);
                i--;
            }
            else if(s[i]=='['){
                strstack.push(curr);
                curr = "";
            }
            else if(s[i]==']'){
                string temp = curr;
                curr = strstack.top();strstack.pop();
                int repeat = numstack.top();numstack.pop();
                while(repeat--){
                    curr+=temp;
                }
            }
            else{
                curr+=s[i];
            }
        }
        return curr;
        
    }
};
int main() {
    Solution sol;
    string s = "3[a2[c]]";
    cout << sol.decodedString(s) << endl; // Output: "accaccacc"
    return 0;
}