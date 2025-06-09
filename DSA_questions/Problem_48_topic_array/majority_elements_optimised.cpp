#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Method : boyer - moore voting algorithm where sc will be O(1).
// single pass to find the majority element , use a second pass to verify if that is correct.
// tc : O(n) sc : O(1)


// hint : The majority element must survive as the final candidate because it appears more times than all other elements combined, so it can't be completely cancelled out.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // majority element will appears more than n/2 times, if we cancel out each occurence of different elements , majority element will remain
        int count = 0,maxEl = 0;
        for(int num:nums){
            if(count == 0) maxEl = num;
            count+=(num==maxEl)?1:-1;
        }
        // if it is mentioned in the problem that it always exist then return it otherwise check in the second pass if that is the majority element
        return maxEl;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << s.majorityElement(nums) << endl;
    return 0;
}
