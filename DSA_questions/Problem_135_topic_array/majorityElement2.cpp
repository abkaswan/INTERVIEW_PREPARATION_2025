#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// time complexity : O(n) { iterating over the array O(n) + inserting unordered_map O(1) on avg for the same} + {iterate over all key-value pairs O(k) k is the number of unique elements , in worst case it is n , so worst case O(n)}
// space complexity : O(n) for the unordered_map in the worst case + O(1) for constants and for the output vector (in this case, at most 2 because only two can be n/3 majorit elements right ?)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> v;
        int n = nums.size();
        for(auto x : nums){
            mpp[x]++;
        }
        for(auto x : mpp){
            if(x.second>n/3){
                v.push_back(x.first);
            }
        }
        return v;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3};
    vector<int> result = sol.majorityElement(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}