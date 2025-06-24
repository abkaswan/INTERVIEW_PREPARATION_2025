#include <iostream>
#include <string>
using namespace std;

// The outer loops (i, j) generate all substrings: O(n²) substrings.
// For each substring, the palindrome check takes O(n) in the worst case (when s[i..j] is long).
// Total time complexity: O(n³) 

// space complexity: O(1) since we are not using any extra space except for a few variables.
class Solution {
public:
    // method 1 : brute force -- using for loops and calculating for every substring.
    bool panlindrome(int i,int j,string s){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size(),maxi=0,firstIndex=0;
        for(int i = 0;i<n;i++){
            for(int j=i;j<n;j++){
                // (0 to 0 , 0 to 1 .... 0--n-1) ,(1 to 1 ...  1--n-1) etc
                if(panlindrome(i,j,s)){
                    if(maxi<(j-i+1)){
                        maxi = j-i+1;
                        firstIndex = i;
                    }
                } 
            }
        }
        // cout<<firstIndex<<"::"<<maxi<<endl;
        return s.substr(firstIndex,maxi);
    }
};
int main()
{
    Solution s;
    string str = "babad";
    string longest = s.longestPalindrome(str);
    cout << longest << endl;
    return 0;
}
