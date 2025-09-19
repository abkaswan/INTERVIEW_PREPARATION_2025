#include<iostream>
#include<stack>
using namespace std;
// time complexity: O(n) and space complexity: O(n)
class Solution {
  public:
    int minParentheses(string& s) {
        int count = 0;
        stack<char> st;
        for(char c : s){
            if(c=='(') st.push(c);
            else{
                if(!st.empty()) st.pop();
                else count+=1;
            }
            
        }
        while(!st.empty()){
            count+=1;
            st.pop();
        }
        return count;
    }
};
int main(){
    Solution sol;
    string s = "())";
    cout<<sol.minParentheses(s)<<endl; // Output: 1
    return 0;
}