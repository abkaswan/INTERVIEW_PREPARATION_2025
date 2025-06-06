#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // time complexity : O(2n) = O(n) each position is calcualted only once , twice for subStart and subEnd
    // space complexity : O(1) no extra space
    int robSum(vector<int>& nums,int l, int r){
        int n = nums.size();
        int prev2=0;
        int prev1=0;
        for(int i = l;i<=r;i++){
            int curr=max(nums[i]+prev2,prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        // method 1 : recursion
        // methdo 2: dp memoization -- recursive
        // method 3 : dp tabulation -- iteartive
        // method 4 : dp fine tuning -- space optimisation
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        int subStart = robSum(nums,0,n-2);
        int subEnd = robSum(nums,1,n-1);
        return max(subStart,subEnd);
        
    }
};

int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // example input
    Solution sol;
    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}
