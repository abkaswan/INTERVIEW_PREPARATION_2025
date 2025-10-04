#include <iostream>
#include <stack>
using namespace std;
// time complexity : O(n) and space complexity : O(n)
class Solution {
public:
    int minAddToMakeValid(string s) {
        // method 1 : use stack to count it 
        stack<char> st;
        int i = 0,res = 0;
        for(auto x : s){
            if(x=='(') st.push(x);
            else{
                if(st.empty()) res++;
                else st.pop();
            }
        }
        while(!st.empty()){
            st.pop();
            res++;
        }
        return res;
    }
};
int main() {
    Solution sol;
    string s = "())";
    cout << sol.minAddToMakeValid(s) << endl; // Output: 1
    return 0;
}