#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// time complexity : O(n) where n is the length of the string
// space complexity : O(k) where k is the number of distinct vowels in the string (at most 10)
class Solution {
public:
    static inline bool isVowel(char c) {
        // ASCII-only check (fast)
        char lc = (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
        return lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u';
    }

    string sortVowels(string s) {
        unordered_map<char,int> vc;
        vc.reserve(10);         // only a few distinct vowel chars possible
        int total = 0;

        // 1) Count occurrences of each vowel (preserve original char)
        for (char c : s) {
            if (isVowel(c)) {
                vc[c]++;
                total++;
            }
        }
        if (total == 0) return s; // nothing to do

        // 2) Produce sorted vowel list in ASCII ascending order
        const string order = "AEIOUaeiou"; // ASCII order we want for vowels
        vector<char> sorted;
        sorted.reserve(total);
        for (char v : order) {
            auto it = vc.find(v);
            if (it != vc.end()) {
                for (int k = 0; k < it->second; ++k)
                    sorted.push_back(v);
            }
        }

        // 3) Reinsert sorted vowels back into the string (modify in-place)
        int idx = 0;
        for (char &c : s) {
            if (isVowel(c)) {
                c = sorted[idx++];
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