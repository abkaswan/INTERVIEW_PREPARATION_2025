#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    int getLPSLength(string &s) {
        // method 2 : double hash prefix-suffix check
        // O(n) time and O(1) space
        // use double rolling hash to compute the hash values, compare them , if match then update the result with the current length
        
        int base1 = 31, base2 =37;
        int mod1 = 1e9+7,mod2 = 1e9+9;
        // prefix power p1 and p2
        int p1 = 1,p2 = 1;
        int n = s.size();
        // hash arrays to store prefix and suffix hashes, 
        vector<int> hash1(2,0), hash2(2,0);
        int ans = 0;
        
        for(int i = 0;i<n-1;i++){
            
            // update the hashes --  prefix hash
            hash1[0] = (hash1[0]+1LL*(s[i]-'a'+1)*p1%mod1)%mod1;
            hash1[1] = (hash1[1]+1LL*(s[i]-'a'+1)*p2%mod2)%mod2;
            
            // update the hashes --  suffix hash
            hash2[0] = (1LL*hash2[0]*base1%mod1+(s[n-i-1]-'a'+1))%mod1;
            hash2[1] = (1LL*hash2[1]*base2%mod2+(s[n-i-1]-'a'+1))%mod2;
            
            if(hash1 == hash2){
                ans = i+1;
            }
            
            //update p1 and p2 here
            p1 = 1LL*p1*base1%mod1;
            p2 = 1LL*p2*base2%mod2;
            
        }
        return ans;
        
    }
};
int main() {
    Solution sol;
    string s = "ababab";
    int result = sol.getLPSLength(s);
    cout << "Length of the longest prefix which is also suffix: " << result << endl; // Output: 4
    return 0;
}