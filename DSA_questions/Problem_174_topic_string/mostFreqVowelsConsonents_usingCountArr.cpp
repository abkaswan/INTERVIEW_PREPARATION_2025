#include<iostream>
#include<string>
using namespace std;
// time complexity : O(n) and space complexity : O(1)
class Solution {
public:
    bool isVowel(int c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxFreqSum(string s) {
        int arr[26] = {0};
        int maxVowel = 0, maxConsonents = 0;
        for(char x : s){
            arr[x-'a']++;
            if(isVowel(x)){
                maxVowel = max(maxVowel,arr[x-'a']);
            }
            else{
                maxConsonents=max(maxConsonents,arr[x-'a']);
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