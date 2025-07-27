#include <iostream>
#include <string>
using namespace std;
// time complexity O(n) and space complexity O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        // method : use sliding window to find the count of all substrings containing all three characters 'a', 'b', and 'c'
        int l = 0, r = 0, n = s.size();
        int countA = 0, countB = 0, countC = 0,res = 0;
        while(r<n){
            if(s[r]=='a') countA++;
            if(s[r]=='b') countB++;
            if(s[r]=='c') countC++;

            while(countA>0 && countB>0 && countC>0){
                res+= (n - r); // Count all valid substrings starting from l to the end of the string
                if(s[l]=='a') countA--;
                if(s[l]=='b') countB--;
                if(s[l]=='c') countC--;
                l++;
            }

            r++;
        }
        return res;
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