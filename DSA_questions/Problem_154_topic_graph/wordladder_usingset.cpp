#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

// Time Complexity =>
// O(N·L) to build unordered_set (N inserts, each hashing a word of length L)
// O(L) to check endWord existence (hash lookup)
// BFS:
//   - Each word processed once
//   - For each word: L positions × 26 letters = O(26·L) candidates
//   - Each candidate requires hashing/comparing string of length L → O(L)
//   - So per word = O(26·L·L) = O(L²)
//   - Across N words = O(N·L²)
// ⇒ Overall: O(N·L²)

// Space Complexity =>
// O(N·L) for unordered_set (stores N words of length L)
// O(N·L) for queue in worst case (stores up to N strings of length L)
// O(L) for temporary word string
// ⇒ Overall: O(N·L)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // for O(1) lookup i am going to use unordered_set
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        // now if i need to find the index in set using find
        // step1 : check if endWord is in the wordList or not if not return 0
        if(st.find(endWord)==st.end()){
            return 0;
        }

        // step2 : start with bfs
        // if the beginword is not in the list add it , but no need to do that because we can just do st.erase(beginWord) if it's not there it would be erased anyway
        st.erase(beginWord);

        // now do the bfs using queue<pair<string,int>> q;
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            auto [word,steps] = q.front();
            q.pop();

            // in this way whoever reaches first will return the answer;
            if(word==endWord) return steps;

            string temp = word;
            for(int i = 0;i<word.size();i++){
                char original = temp[i];
                for(char c = 'a';c<='z';c++){
                    temp[i] = c;
                    if(st.find(temp)!=st.end()){
                        st.erase(temp);
                        q.push({temp,steps+1});
                    }
                }
                temp[i]=original;
            }
        }

        return 0; // no transformation possible
    }
};
int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;  // Output: 5
    return 0;
}