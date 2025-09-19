#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
    }
};
int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);
    
    for (const auto& path : result) {
        for (const auto& word : path) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}