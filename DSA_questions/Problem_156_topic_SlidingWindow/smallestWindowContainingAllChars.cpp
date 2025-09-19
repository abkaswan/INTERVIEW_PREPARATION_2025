#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// time complexity O(n) and space complexity O(1)
class Solution {
  public:
    string smallestWindow(string &s, string &p) {
       // method : sliding window approach 
       // step 1 : count the freq in string p 
       if(s.size()<p.size()) return "";
       
       vector<int> need(256,0), have(256,0);
       for(auto x : p) need[x]++;
       // step 2 : get the required chars 
       int required = 0;
       for(int i = 0;i<256;i++){
           if(need[i]>0) required++;
       }
       int formed = 0;
       // step 2 ; do the sliding window now
       int l = 0, r = 0;
       int minlen = INT_MAX;
       int start=0; // to get the starting index understood?
       while(r<s.size()){
           char c = s[r];
           have[c]++;
           
           if(need[c]>0 && have[c]==need[c]) formed++;
           
           // when formed has reached at a point means we have found our all characters of p in s 
           // now calculate the length and again try to reduce the formed and repeat the cycle , if formed is still equal to required that means there is still a chance to get the minlen yet so calculate the minlen again
           
           // try to shrink the window
           while(l<=r && formed==required){
               if(r-l+1<minlen){ minlen = r-l+1;start = l;}
               
               
               have[s[l]]--;
               if(have[s[l]]<need[s[l]]){
                   formed--;
               }
               
               l++;
               
           }
           r++;
           
           
       }
       return minlen==INT_MAX?"":s.substr(start,minlen);
    }
};
int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string p = "ABC";
    string result = sol.smallestWindow(s, p);
    cout << "Result: " << result << endl; // Output: "BANC"
    return 0;
}