#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;
// time complexity : O(d) where d is number of digits in n
// space complexity : O(1)
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        // method 1 : use unordered_map or vector -- using this one
        // method 2 : use sorting
        vector<int> v(10,0);
        while(n>0){
            v[n%10]++;
            n = n/10;
        }
        // least freq and smallest digit among them
        int res = -1,count = INT_MAX;
        for(int i = 0;i<10;i++){
            if(v[i]>0 && count>v[i]){
                count = v[i];
                res = i;
            }
            
        }
        return res;
    }
};
int main() {
    Solution sol;
    int n = 1553322;
    int result = sol.getLeastFrequentDigit(n);
    cout << "Least Frequent Digit: " << result << endl; // Output: 1
    return 0;
}
