#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n) 
// space complexity : O(1) for the constants and for the output vector (in this case, at most 2 because only two can be n/3 majorit elements right ?)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // boyer -- moore algo
        int cnt1 = 0, cand1 = 0, cnt2 = 0, cand2 = 0;
        vector<int> v;
        for(int i = 0;i<nums.size();i++){

            
            if(nums[i]==cand1) cnt1++; // first we check this because if not we might assign this same candidate to cand2 also by this condition cand2 = nums[i] so do this first 
            else if(nums[i]==cand2) cnt2++;
            else if(cnt1==0){cand1 =nums[i];cnt1 = 1;}
            else if(cnt2 ==0){ cand2 = nums[i];cnt2 = 1;}
            
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 =0,cnt2 = 0;
        for(auto x : nums){
            if(x==cand1) cnt1++;
            else if(x==cand2) cnt2++;
        }
        if(cnt1>nums.size()/3) v.push_back(cand1);
        if(cnt2>nums.size()/3) v.push_back(cand2);
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