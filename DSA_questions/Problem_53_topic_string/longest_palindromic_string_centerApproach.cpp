#include <iostream>
#include <string>
using namespace std;

//Q1: Length issue why is it r-l-1 ?
//      But when the loop stops: l has gone one step too far left (i.e., s[l] != s[r]) , r has gone one step too far right
//      So the valid palindrome is actually from index l+1 to r-1. now if you calculate length is it (r-1)-(l+1)+1 = r-l-1 so that's why it is like this.

//Q2: why is start = i-(len-1)/2; ?
//      When we find a palindrome of length len centered at index i, the leftmost index of this palindrome is i - (len - 1) / 2. because (len - 1) / 2 gives the distance from the center to the left edge of the palindrome.

class Solution {
public:
    //total 2n-1 centers we will check with odd and even centers
    // tc: O(n^2) sc : O(1)
    int expand(int l,int r,string& s){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = 1,start = 0;
        for(int i = 0;i<n;i++){
            int odd = expand(i,i,s);
            int even = expand(i,i+1,s);
            int len = max(even,odd);
            if(len>maxi){
                maxi = len;
                start = i-(len-1)/2; // this would be l in this case so i maybe ?
            }

        }
        return s.substr(start,maxi);
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
