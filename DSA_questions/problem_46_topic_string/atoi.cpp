#include <iostream>
#include <string>
#include <climits>

using namespace std;
// time complexity : O(n) where n is the length of the string
// space complexity : O(1) since we are using a constant amount of space
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1,res=0;
        bool start = false;
        for(char c : s){
            // ignore the whitespace if it has not begun 
            if(start == false && c==' ') continue;
            // get the sign or by default it will be + , do it if it is the first non-whitespace character otherwise not
            if(start == false && (c=='-' || c=='+')){
                sign = (c=='-')?-1:1;
                start = true;
                continue;
            }            
            
            // zeroes ignore and add the nubmers to the result
            else if(c>='0' && c<='9'){
                //because INT_MAX is 2147483647 so INT_MAX/10 is 214748364 so res*10 is = 2147483640 so if we do digit > 7 then it will overflow till 7 it is fine that is why the extra condition is there
                if(res>INT_MAX/10 || (res==INT_MAX/10 && c-'0'>7))
                {
                    return sign==1?INT_MAX:INT_MIN;
                }

                res=res*10+(c-'0');
                start = true;
            }
            //after whitespace && if non-digit is encountered then return the res;
            else break;
            
        }
        return sign*res; 
    }
};
int main() {
    Solution solution;
    string input = "42";
    int result = solution.myAtoi(input);
    cout << "The integer is: " << result << endl;
    return 0;
}

