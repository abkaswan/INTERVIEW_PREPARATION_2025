#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
// time complexity : O(n) and space complexity : O(1)
class Solution {
public:
    bool isVowel(int c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxFreqSum(string s) {
        unordered_map<char,int> mpp;
        int maxVowel = 0, maxConsonents = 0;
        for(char x : s){
            mpp[x]++;
            if(isVowel(x)){
                maxVowel = max(maxVowel,mpp[x]);
            }
            else{
                maxConsonents=max(maxConsonents,mpp[x]);
            }
        }
        return maxVowel+maxConsonents;
    }
};
int main(){
    Solution sol;
    string s = "abciiidef";
    cout<<sol.maxFreqSum(s)<<endl;
    return 0;
}