#include <iostream>
#include <string>
using namespace std;
// time complexity: O(n*m) in worst case, average O(n+m) and space complexity: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
int main() {
    Solution sol;
    string haystack = "hello";
    string needle = "ll";
    int index = sol.strStr(haystack, needle);
    cout << "Index of first occurrence: " << index << endl; // Output: 2
    return 0;
}