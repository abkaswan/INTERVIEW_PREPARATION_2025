#include<iostream>
#include<string>
using namespace std;
// time complexity : O(n) and space complexity : O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        // method 2 : use pointers to count it
        int i = 0,open = 0,close = 0;
        for(auto x : s){
            if(x=='(') open++;
            else{
                if(open>0) open--;
                else close++;
            }
        }
        
        return (open+close);
    }
};
int main(){
    Solution sol;
    string s = "())";
    cout<<sol.minAddToMakeValid(s);
    return 0;
}