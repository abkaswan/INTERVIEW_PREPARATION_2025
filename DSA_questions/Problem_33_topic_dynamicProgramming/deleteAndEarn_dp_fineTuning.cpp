// time complexity ; O(n + m) where m is the maximum number in array : nums
// space complexity : O(m) to store the vector v
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // turn this into house robber problem 
        vector<int> v(10001,0);
        for(int i = 0;i<nums.size();i++){
            v[nums[i]]+=nums[i];
        }

        //now we have the i:the number and v[i]: as the count of that number
        // need to ignore i+1 and i-1 , we don't need to include those , and get the max count we can get , same as house robber problem
        int n = v.size();
        int prev3 = v[0];
        int prev2 = v[1];
        int prev1 = v[2]+max(prev3,0);
        for(int i = 3;i<n;i++){
            int curr = v[i]+max(prev2,prev3);
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return max(prev1,prev2);
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    int result = sol.deleteAndEarn(nums);

    cout << "Result: " << result << endl;

    return 0;
}