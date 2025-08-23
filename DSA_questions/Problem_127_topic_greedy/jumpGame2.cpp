#include <iostream>
#include <vector>
using namespace std;
// time complexity: O(n)
// space complexity: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0,jumps = 0;
        int currEnd = 0;

        // here maxReach is : max index reachable from current range or in simpler terms furhtest you can reach from your current position
        // here currEnd is : end of the current range's jump
        
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            if(i>maxReach) return -1;
            maxReach = max(maxReach,i+nums[i]);
            if(i==currEnd){
                currEnd = maxReach;
                jumps++;
            }
        }
        return jumps;

    }
};
int main() {
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    int result = sol.jump(nums);
    cout << "Minimum jumps required: " << result << endl; // Output: 2
    return 0;
}
