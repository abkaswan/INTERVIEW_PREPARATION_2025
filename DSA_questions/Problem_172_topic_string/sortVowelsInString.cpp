#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity : O(n + m) where n is the length of the string and m is the range of characters (constant here, 256)
// space complexity : O(m) for the count array
class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c); // Convert to lowercase for easier comparison
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string sortVowels(string s) {
        // can use count sort for this
        // step 1 : separte list for the vowels
        int totalVowels = 0;
        vector<int> vowel_count(256,0);

        for(auto x: s){
            if(isVowel(x)){
                totalVowels++;
                vowel_count[x]++;
            }
        }
        // step 2 : check if there are no vowels then return the string as it is only 
        if(totalVowels == 0) return s;
        // step 3 : use count sort to sort the list
        int idx = 0;
        for(char &c : s){
            if(isVowel(c)){
                // add it from the vector right ?
                // find the next available vowel in ascending order
                while(idx<256 && vowel_count[idx]==0) idx++;
                // now replace it in the original string
                c = (char)idx;
                vowel_count[idx]--;
            }
        }
        return s;
    }
};
int main() {
    Solution sol;
    string s = "leetcodeisacommunityforcoders";
    string result = sol.sortVowels(s);
    cout << result << endl; // Output: "leotcedeisacommunityforcoders"
    return 0;
}