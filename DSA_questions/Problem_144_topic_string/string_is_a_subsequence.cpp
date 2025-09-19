#include<iostream>
#include<string>

using namespace std;

class Solution {
  public:
    // time complexity : O(n1+n2) but n2 dominates as it is larger most of the time
    // space complexity : O(1)
    bool isSubSeq(string& s1, string& s2) {
        // subsequence is same order but need not to be consecutive chars like substring
        
        // naive approach : check if the char i is in string s2 where i is from s1={0,n1} and keep moving forward in string s2 also using j
        int n1 = s1.size();
        int n2 = s2.size();
        int j = 0, i = 0;

        while(i<n1 && j<n2) {
            if(s1[i] == s2[j]) {
                i++;
            }
            j++;
        }
        return i==n1;
        
    }
};
int main() {
    Solution obj;
    string s1 = "abc";
    string s2 = "ahbgdc";
    if(obj.isSubSeq(s1,s2)) cout<<"s1 is a subsequence of s2"<<endl;
    else cout<<"s1 is not a subsequence of s2"<<endl;
    return 0;
}
