#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// here we are gonna use two pointers and combinatorial approach
// step 1 : sort the array 
// step 2 : use two pointers , for l and r , get the pairs that satisfy the condition (nums[l] + nums[r] <= target)
// any subset between r-l will be valid for the count  , which is equal to 2^(r-l)
// step 3 : count + = (2^(r-l))%MOD
// this is the final answer

// Time complexity : O(nlogn) // for sorting and for the function to calculate powers
// space complexity : O(1)

class Solution {
    public:
        const int MOD = 1e9 + 7;
        long long modPower(long long base, long long exp) {
            long long res = 1;
            while(exp){
                if(exp & 1) res = (res*base)%MOD;
                base = (base*base)%MOD;
                exp = exp>>1;
            }
            return res;
        }
        int numSubseq(vector<int>& nums, int target) {
            int count = 0;
            sort(nums.begin(),nums.end());
            int l = 0 , r = nums.size()-1;
            while(l<=r){
                if(nums[l]+nums[r]<=target){
                    count = (count + modPower(2,r-l))%MOD;
                    l++;
                }
                else{
                    r--;
                }
            }
            return count;
        }
};
int main() {
    vector<int> nums = { 3,5,6,7};
    int k = 9; // your target sum here

    Solution sol;
    int result = sol.numSubseq(nums, k);
    cout << "Result: " << result << endl;

    return 0;
}