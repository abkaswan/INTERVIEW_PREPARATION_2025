#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity : O(n)
// space complexity : O(1)
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // brute force : use two for loops and calculate it 
        // method 2 : using two pointer
        int n = arr.size();
        int l = 0, r = n-1,currRes = 0,maxRes = 0;
        while(l<r){
            currRes = min(arr[l],arr[r])*(r-l);
            maxRes = max(maxRes,currRes);
            // move the smaller height because height is the limitng factor here
            // if both are same move either it will work
            if(arr[l]<arr[r]) l++;
            else r--;
            
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