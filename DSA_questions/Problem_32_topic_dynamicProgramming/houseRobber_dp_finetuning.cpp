#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        // recursive apporoach : O(2^n)
        // method 2 : trying top to bottom -- memoization , O(2N) tc and O(N) sc
        // method 3 : bottom to up -- iterative approach , O(n) tc and O(n) sc
        // method 4 : using pointers maybe O(n) tc and O(1) sc
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        int prev3=nums[0];
        int prev2=nums[1];
        int prev1=nums[2]+max(prev3,0);
        for(int i = 3;i<n;i++){
            int curr=nums[i]+max(prev2,prev3);
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return max(prev1,prev2);

    }
};
int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // example input
    Solution sol;
    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}

