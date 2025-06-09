#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// tc : O(n) { iterating over the array O(n) + inserting unordered_map O(1) on avg for the same} + {iterate over all key-value pairs O(k) k is the number of unique elements , in worst case it is n , so worst case O(n)}
// sc : O(n) { map to store counts for unique elements , worst case : O(n) } + {O(1) for constants}
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int i = nums.size();
        for(auto i:nums){
            mpp[i]++;
        }
        //return the max element now 
        int maxElement = 0, maxCount = 0;
        for (const auto& pair : mpp) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                maxElement = pair.first;
            }
        }
        return maxElement;

    }
};
int main()
{
    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << s.majorityElement(nums) << endl;
    return 0;
}
