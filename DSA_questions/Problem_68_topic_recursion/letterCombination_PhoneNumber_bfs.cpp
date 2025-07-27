#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// time complexity : O(4^n) : each digit can map to 3 or 4 letters, leading to a total of 3^n or 4^n combinations.building each combination takes O(n) time, where n is the length of the digits string but we do swap and not copy the string so it will take O(1) time for each combination
// space complexity : at most you store O(4^n) strings of n length in the result vector, so O(4^n * n) for the result vector. The unordered_map takes O(1) space since it has a fixed size of 8 entries (for digits 2-9). and temp vector is there, but since we are swapping it with res, we do not count it in the final space complexity
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res={""};
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
        for(char digit : digits){
            vector<string> temp;
            for(string& comb:res){
                for(char ch:mpp[digit]){
                    temp.push_back(comb+ch);
                }
            }
            res.swap(temp);
        }
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