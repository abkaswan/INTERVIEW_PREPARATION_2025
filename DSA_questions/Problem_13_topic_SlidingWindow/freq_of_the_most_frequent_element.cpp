#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        //sort the array 
        sort(nums.begin(),nums.end());
        //now take the sliding window approach and try to make
        // let's say for a element nums[i] we will need to see the elements in the left and how much it costs to increase them to nums[i]
        int l = 0, r = 0;
        int n = nums.size(),maxLen = 0;
        long long cost = 0,sumWindow=0;
        
        while(r<n){
            
            // cost would be : nums[r]*(r-l+1) -- when all the elements are nums[r] equvalient let's say it x, and (sumOfWindowElements) -- let's call it y , answer would be x-y , you can think about it also 
            sumWindow+=nums[r];
            cost = 1ll*(r-l+1)*nums[r]-sumWindow;
            while(cost>k){
                //reset the sum so that cost would be udpated also for the next window
                sumWindow-=nums[l++];
                cost = 1ll*(r-l+1)*nums[r]-sumWindow; //update the cost also so that we can go out of the for loop
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};
int main() {
    vector<int> nums = {1, 2, 4};
    int k = 5;
    Solution sol;
    int result = sol.maxFrequency(nums, k);
    cout << "Maximum possible frequency: " << result << endl;
    return 0;
}

