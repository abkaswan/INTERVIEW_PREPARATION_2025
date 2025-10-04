#include<iostream>
#include<vector>
using namespace std;

// time complexity : O(2^n) where n is the size of the array and space complexity : O(n) for the recursion stack
class Solution {
public:
    bool checkPartition(int i,vector<int>& nums,int sum1,int sum2){
        if(i==nums.size()){
            if(sum1==sum2) return true;
            return false;
        }
        // two choices either include the i in first subset or the second one? take two sums sum1 and sum2 for this and then decide
        return checkPartition(i+1,nums,sum1+nums[i],sum2) || checkPartition(i+1,nums,sum1,sum2+nums[i]);
    }
    bool canPartition(vector<int>& nums) {
        // method 1 : recursion
        return checkPartition(0,nums,0,0);
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,5,11,5};
    cout<<s.canPartition(nums);
    return 0;

}