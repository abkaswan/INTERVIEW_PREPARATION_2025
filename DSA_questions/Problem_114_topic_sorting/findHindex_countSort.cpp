#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n) 
// space complexity : O(n) for count array
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        // do it the same way you did brute force there you used O(n^2) time and O(1) space this time do O(n) time and O(n) space
        vector<int> count(n+1,0);
        for(int i = 0;i<n;i++){
            if(citations[i]>=n) count[n]++;
            else count[citations[i]]++;
        }
        int total = 0;
        for(int i = n;i>=0;i--){
            total+=count[i];
            if(total>=i) return i;
        }
        return 0;

    }
};
int main() {
    Solution sol;
    vector<int> citations = {3, 0, 6, 1, 5};
    int result = sol.hIndex(citations);
    cout << "H-Index: " << result << endl; // Output: H-Index: 3
    return 0;
}