#include <iostream>
#include <vector>
using namespace std;
// time complexity O(n^2) and space complexity O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0,j = 0;
        int n = nums.size(),count = 0;
        
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j = i;j<n;j++){
                sum+=nums[j];
                if(sum==goal) count+=1;
            }
        }
        return count;
        
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