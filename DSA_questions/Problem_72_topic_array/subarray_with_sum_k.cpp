#include <iostream>
#include <vector>
using namespace std;
// time O(n^2)
// space O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),count = 0;
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j = i;j<n;j++){
                sum+=nums[j];
                if(sum==k) count+=1;
            }
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << sol.subarraySum(nums, k) << endl;  // Output: 2
    return 0;
}