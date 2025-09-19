#include<iostream>
using namespace std;
// time complexity: O(n) and space complexity: O(1)
class Solution {
  public:
    int minParentheses(string& s) {
        int count = 0;
        int open = 0;
        // if open parenthesis is there so count that as open+=1
        for(int i = 0;i<s.size();i++){
            if(s[i]=='(') open+=1;
            
            else{
                // if it is close , then see if open is left , if not do count+=1
                if(open>0) open-=1;
                else count+=1;
            }
        }
        // add the remaining open parenthsis also
        count+=open;
        return count;
    }
};
int main(){
    Solution sol;
    string s = "())";
    cout<<sol.minParentheses(s)<<endl; // Output: 1
    return 0;
}