#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n) , space complexity : O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        // the key concept is this the pattern should be decreasing to increasing window and inside that window we will have our answers
        // how do we calculate it : what is the maximum height on the left for particular index and what is one the right , now for that index i the answer would be min of them minus their own height right
        // so min(maxLeft(i),maxRight(i)) - arr[i] and keep adding we will have total trapped water

        // step1 : calculate the maxLeft and maxRight arrays , maxRight is maximum from i to n-1 , maxLeft is maximum from 0 to i
        int n = height.size();
        vector<int> maxLeft(n,0),maxRight(n,0);
        int maxEle = 0;
        for(int i = 0;i<n;i++){
            // maximum so far
            maxEle = max(maxEle,height[i]);
            maxLeft[i] = maxEle;
        }
        //reset maxEle
        maxEle = 0;
        for(int i = n-1;i>=0;i--){
            // maximum so far -- from reverse
            maxEle = max(maxEle,height[i]);
            maxRight[i] = maxEle;
        }
        // step2 : calculate the result using the formula
        int res = 0;
        for(int i = 0;i<n;i++){
            res+=(min(maxLeft[i],maxRight[i]))-height[i];
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<sol.trap(height)<<endl; // Output: 6
    return 0;
}