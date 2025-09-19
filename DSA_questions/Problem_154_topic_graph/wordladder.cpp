#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

// Time Complexity =>
// O(N·L) to build unordered_map (N inserts, each hashing string of length L)
// O(N) to initialize visited array
// O(N·L²) for BFS (each of up to N words expands into 26·L neighbors, 
//                each neighbor check costs O(L) for hashing/comparison)
// ⇒ Overall: O(N·L²)

// Space Complexity =>
// O(N·L) for unordered_map (stores all N words of length L)
// O(N) for visited array
// O(N·L) for queue in worst case (stores up to N strings of length L)
// O(L) for temporary word copies
// ⇒ Overall: O(N·L)


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // for O(1) lookup i am going to use unordered_map
        unordered_map<string,int> mpp;
        for(int i = 0;i<wordList.size();i++){
            mpp[wordList[i]] = i;
        }
        // now if i need to find the index do mpp[target]
        // step1 : check if endWord is in the wordList or not if not return 0
        if(mpp.count(endWord)==0){
            return 0;
        }

        // step2 : start with bfs
        // if the beginword is not in the list add it
        if(mpp.count(beginWord)==0){
            wordList.push_back(beginWord);
            mpp[beginWord] = wordList.size()-1;
        }

        // now do the bfs using queue<pair<string,int>> q;
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        // visited to see if it has been visited or not
        vector<bool> visited(wordList.size(),false);
        visited[mpp[beginWord]] = true;

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
                    if(mpp.count(temp) && !visited[mpp[temp]]){
                        visited[mpp[temp]] = true;
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