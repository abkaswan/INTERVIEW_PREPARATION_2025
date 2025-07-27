#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// time complexity O(n) and space complexity O(1)
class Solution {
public:
    int sol(vector<int>& nums,int goal){
        int l = 0,r = 0,n=nums.size(),sum = 0, count = 0;
        if(goal<0) return 0; // in case goal = 0 and goal-1 becomes -1 we put this condition

        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l++];
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // method 2 : if we are doing two pointers directly it is not working because we are confused whether to move l or r , in each case some of the subarrays are gettign missed
        // idea : find where sum<=goal
        // #subarrays with sum ≤ goal  -  #subarrays with sum ≤ (goal - 1)
        return sol(nums,goal)-sol(nums,goal-1);
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    int result = sol.numSubarraysWithSum(nums, goal);
    // Output the result
    cout << "Number of subarrays with sum " << goal << ": " << result << endl;
    return 0;
}