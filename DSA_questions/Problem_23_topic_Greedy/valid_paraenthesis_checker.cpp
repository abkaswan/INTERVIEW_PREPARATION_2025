#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        // so for left we will take count as +1
        // for right we will take count as -1
        // take count for * also , if count<0 and countStar>0 countStar-- and 
        int count1 = 0,count2 = 0,countStar = 0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='('){
                count1++;
                count2++;
            }
            else if(s[i]==')') {
                count1--;
                count2--;
            }
            // let's take count1 as ) so when we go through the list if there is no closing paranthesis we give it using count1
            // let's take count2 as ( so when we go through string if there is no opening paranthesis left we give it using count2
            else if(s[i]=='*'){
                count1--;
                count2++;
            }
            // what happens now is that if there are any substring where count2 is negative means even though we have given ( it was not enough so return false
            if(count2<0) return false;
            count1=max(0,count1);
        }
        return count1==0;
    }
};
int main() {
    Solution sol;
    string s;
    cin >> s;
    bool result = sol.checkValidString(s);
    cout << result << endl;
    return 0;
}
