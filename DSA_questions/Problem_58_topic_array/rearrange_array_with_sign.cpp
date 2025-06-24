#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        // not in place : take two arrays positives, negatives and then merge it O(N) and O(N)
        for(int i = 0;i<n;i++){
            if(nums[i]<0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }
        int j = 0,k = 0;
        for(int i = 0;i<n;i++)
        {
            if(i%2==0) nums[i]=pos[j++];
            else nums[i]=neg[k++];
        }
        return nums;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-1,2,-3,4,-5,6,-7,8};
    vector<int> result = s.rearrangeArray(nums);
    for(int i = 0;i<result.size();i++)
        cout<<result[i]<<" ";
    return 0;
}
