#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int count=0;
    void funo(vector<int>& nums,int k,int i,int sum){
        if(sum>k || i==nums.size()){
            if(sum==k){count+=1;}
            return;
        }
        funo(nums,k,i+1,sum+nums[i]); // here we are including nums[i] , so when 9->2 it goes it returns to 9 but it can't go to any other call like 5 again because we haven't called that right ? so for that we will need to call again one more recursive call where we exclude the current element
        funo(nums,k,i+1,sum);// here we are excludin nums[i]
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        
        funo(nums, k, 0, 0);
        return count;
    }
};

int main() {
    vector<int> nums = { 4, 9, 2, 5, 1 };
    int k = 10; // your target sum here

    Solution sol;
    int result = sol.countSubsequenceWithTargetSum(nums, k);

    cout << "Result: " << result << endl;

    return 0;
}
