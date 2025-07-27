#include <iostream>
#include <vector>
#include <string>
using namespace std;
// time complexity : O(4^n) because at each time we are having max 4 choices so the total number of combination is : 4*4*4.... till n , = 4^n and the resultant string we are doing push_back and pop_back so it will take constant time or the overall at each step O(1) time not copying again and again
// space complexity : O(n) for the recursion stack space + O(4^n*n) for the resultant vector of strings
class Solution {
public:
    void fn(string &s,vector<string>&res, string digits,int i,unordered_map<char,string>&mpp) {
        if(i>=digits.size()){
            res.push_back(s);
            return;
        }
        for(int j = 0;j<mpp[digits[i]].size();j++){
            s+=mpp[digits[i]][j];
            fn(s,res,digits,i+1,mpp);
            s.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        unordered_map<char,string> mpp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string s;
        fn(s,res,digits,0,mpp);
        return res;
    }
};
int main() {
    Solution sol;
    string digits = "23";
    vector<string> result = sol.letterCombinations(digits);
    for (const string& combination : result) {
        cout << combination << " ";
    }
    cout << endl;
    return 0;
}