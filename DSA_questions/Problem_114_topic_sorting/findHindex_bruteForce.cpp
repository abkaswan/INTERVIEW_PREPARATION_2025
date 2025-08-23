#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // meaning how many paper is there H , is there citation value greater than or equal to H if not reduce that H vlaue ?
        int n = citations.size();
        
        // initiallhy h = n
        // so time complexity for this one is : O(n*h) and space is O(1) for now
        int h = n;
        while(h){
            int count = 0;
            for(int i = 0;i<n;i++){
                if(citations[i]>=h) count++;
            }
            if(count >= h) break;
            h--;
        }
        return h;
    }
};
int main() {
    Solution sol;
    vector<int> citations = {3, 0, 6, 1, 5};
    int result = sol.hIndex(citations);
    cout << "H-Index: " << result << endl; // Output should be 3
    return 0;
}