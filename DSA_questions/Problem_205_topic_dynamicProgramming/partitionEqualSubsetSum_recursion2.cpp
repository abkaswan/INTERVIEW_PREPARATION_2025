#include<iostream>
#include<vector>
using namespace std;
// time complexity : O(2^n) where n is the size of the array and space complexity : O(n) for the recursion stack
class Solution {
public:
    bool checkPartition(int i,vector<int>& nums,int sum1,int target){
        if(sum1 == target) return true;
        if(i==nums.size() || sum1>target){
            return false;
        }
        // two choices either include current element for sum1 or not include
        return checkPartition(i+1,nums,sum1+nums[i],target) || checkPartition(i+1,nums,sum1,target);
    }
    bool canPartition(vector<int>& nums) {
        // method 2 : recursion but slightly different 
        // we need sum1 and sum2 to be equal that means sum1+sum2 = totalSum  --> 2*sum1 = totalSum;
        // sum1 = totalSum/2 so if we do it for sum1 = target then it works
        int totalSum = 0;
        for(auto x : nums) totalSum+=x;
        if (totalSum % 2 != 0) return false; // odd sum → impossible
        int target = totalSum/2;
        return checkPartition(0,nums,0,target);
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,5,11,5};
    cout<<s.canPartition(nums);
    return 0;

}