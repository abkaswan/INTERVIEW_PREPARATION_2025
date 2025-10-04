#include<iostream>
#include<vector>
using namespace std;
// time complexity O(n) space complexity O(1)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // so whichever is having max frequency need to send those count
        // it is till 100 only we can take a count array
        vector<int> freq(101,0);
        int maxi = 0;
        for(auto x : nums){
            freq[x]++;
            maxi = max(maxi,freq[x]);
        }
        int res=0;
        for(auto y : freq){
            if(y==maxi) res+=y;
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