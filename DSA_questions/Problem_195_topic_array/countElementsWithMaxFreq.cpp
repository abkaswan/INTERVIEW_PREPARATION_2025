#include<iostream>
#include<vector>
using namespace std;
// time complexity O(n) space complexity O(1)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // so whichever is having max frequency need to send those count
        // it is till 100 only we can take a count array
        vector<int> v(101,0);
        for(int i = 0;i<nums.size();i++){
            v[nums[i]]++;
        }
        int maxi = 0;
        for(int i = 1;i<101;i++){
            if(maxi<v[i]) maxi = v[i];
        }
        int res=0;
        for(int i = 0;i<101;i++){
            if(v[i]==maxi) res+=v[i];
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,2,3,3,3,4,4,4,4};
    cout<<sol.maxFrequencyElements(nums);
    return 0;
}