#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// time complexity O(n) and space complexity O(1)
class Solution {
public:
    int fn(vector<int>& nums,int k){
        int l = 0,r = 0,n = nums.size();
        int sum = 0,minSum = INT_MAX,window = n-k;
        while(r<n){
            sum+=nums[r];
            while(r-l+1>window){
                sum-=nums[l++];
            }
            if(r-l+1==window) minSum = min(minSum,sum);
            r++;
        }
        return minSum;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        // step 1 : get the total sum 
        // step 2 : find the min sum subarray of n-k length
        // step 3 : total-minSumSubarray will be the answer
        int n = cardPoints.size();
        int total = 0;
        for(auto it:cardPoints)
            total+=it;
        return total-fn(cardPoints,k);
    }
};
int main() {
    Solution sol;
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout << sol.maxScore(cardPoints, k) << endl;
    return 0;
}