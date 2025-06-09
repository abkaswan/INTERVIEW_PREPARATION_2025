#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int countSubstring(string s) {
        int counta = 0,countb = 0, countc =0,sum = 0;
        int n = s.size(),l=0,r=0;
        //total moves are O(n)+O(n) because when l moves it doesn't go backward ever it goes forward , r goes from 0 to n also always forward.
        while(r<n){
            if(s[r]=='a') counta+=1;
            if(s[r]=='b') countb+=1;
            if(s[r]=='c') countc+=1;
                
            while(counta>=1 && countb>=1 && countc>=1)
            {
                //take the r which is where we can start the extra substring, do lastIndex-index r+1 for the total possible substring for this
                sum+=(n-r);
                //then reset counta, countb, countc again 
                if(s[l]=='a') counta-=1;
                if(s[l]=='b') countb-=1;
                if(s[l]=='c') countc-=1;
                l++;
            }
            r++;
        }
        return sum;
    }
};
int main() {
    Solution sol;
    cout << sol.countSubstring("abcabc") << endl; // 10
    cout << sol.countSubstring("aaacb") << endl; // 3
    cout << sol.countSubstring("abcbcc") << endl; // 4
    return 0;
}
