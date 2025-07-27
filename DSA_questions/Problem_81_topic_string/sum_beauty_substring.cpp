#include <iostream>
#include <vector>
#include <string>
using namespace std;
// time complexity: O(n^2 * 26)
// space complexity: O(26) = O(1) since the size of the frequency array is constant
class Solution {
public:
    int beautySum(string s) {
        int n = s.size(),sum = 0;
        for(int i = 0;i<n;i++){
            //reset freq for each starting point right ?"aabcb"
            vector<int> v(26,0);
            for(int j = i;j<n;j++){
                // save the frequency
                v[s[j]-'a']++;
                // get the max and min from the array
                int maxi = 0,mini = INT_MAX;
                for(int k=0;k<26;k++){
                    if(v[k]>0){
                        mini = min(mini,v[k]);
                        maxi = max(maxi,v[k]);
                    }
                }
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};
int main() {
    Solution sol;
    string s = "aabcb";
    int result = sol.beautySum(s);
    cout << "The sum of beauty of all substrings is: " << result << endl;
    return 0;
}