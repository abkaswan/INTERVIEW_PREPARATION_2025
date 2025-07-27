#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// time complexity O(n) and space complexity O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // get the hash and then keep checking if we have the next element , using set for O(1) lookups and deduplication
        int maxLen = 0;
        unordered_set<int> mpp;
        for(auto it : nums){
            mpp.insert(it);
        }
        for(auto it : mpp){
            // if the previous number is not in the set then only enter because otherwise we might have checked you in the previous process right ?
            if(!mpp.count(it-1)){
                // find consecutive numbers
                int curr = it;
                int count = 1;
                while(mpp.count(curr+1)){
                    curr++;
                    count++;
                }
                maxLen = max(maxLen,count);
            }
        }
        return maxLen;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}