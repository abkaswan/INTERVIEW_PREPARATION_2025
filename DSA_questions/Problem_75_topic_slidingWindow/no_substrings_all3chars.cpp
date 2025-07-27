#include <iostream>
#include <string>
using namespace std;
// time complexity O(n) and space complexity O(1)
class Solution {
public:
    int fn(string s){
        int l = 0, r = 0, n = s.size();
        int countA = 0, countB = 0, countC = 0,res = 0;
        while(r<n){
            if(s[r]=='a') countA++;
            if(s[r]=='b') countB++;
            if(s[r]=='c') countC++;

            while(countA>0 && countB>0 && countC>0){
                if(s[l]=='a') countA--;
                if(s[l]=='b') countB--;
                if(s[l]=='c') countC--;
                l++;
            }

            res+=(r-l+1);
            r++;
        }
        return res;
    }
    int numberOfSubstrings(string s) {
        // method : find the count where the total number of characters is less than 3 , then sustract it from total no of substring possible , we will get our answer
        long long n = s.size();
        long long total = n*(n+1)/2;//total substrings
        return total-fn(s);
    }
};
int main() {
    Solution sol;
    string s = "abcabc";
    int result = sol.numberOfSubstrings(s);
    // Output the result
    cout << "Number of substrings containing all three characters: " << result << endl;
    return 0;
}