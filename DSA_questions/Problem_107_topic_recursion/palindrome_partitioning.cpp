#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        return {{"this"}};
    }
};
int main() {
    Solution sol;
    string s = "aab";
    vector<vector<string>> result = sol.partition(s);
    for (const auto& partition : result) {
        cout << "[";
        for (const auto& str : partition) {
            cout << "\"" << str << "\",";
        }
        cout << "\b]" << endl;
    }
    return 0;
}