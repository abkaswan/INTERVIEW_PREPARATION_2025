#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity : O(n^2)
// space complexity : O(1)
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // brute force : use two for loops and calculate it 
        int n = arr.size();
        int maxRes = 0,currRes = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                currRes = (abs(j-i))*(min(arr[j],arr[i]));
                maxRes = max(maxRes,currRes);
            }
        }
        return maxRes;
        
    }
};
int main() {
    Solution s;
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    cout << s.maxWater(arr) << endl;
    return 0;
}