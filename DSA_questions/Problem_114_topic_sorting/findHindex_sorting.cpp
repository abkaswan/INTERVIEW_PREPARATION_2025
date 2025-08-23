#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std; 
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        int h = 0;
        sort(citations.begin(),citations.end(),greater<int>()) ; //O(nlogn) - sort in descending order
        
        for(int i = 0;i<n;i++){
            if(citations[i]>=i+1) h = i+1;
            else break;
        }
        return h;
    }
};
int main() {
    Solution sol;
    vector<int> citations = {3, 0, 6, 1, 5};
    int result = sol.hIndex(citations);
    cout << "H-Index: " << result << endl; // Output: H-Index: 3
    return 0;
}