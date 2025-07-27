#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int sol(vector<int>& nums,int k){
        if(k<0) return 0;
        int l = 0, r = 0, n = nums.size(),count = 0,res = 0;
        while(r<n){
            if(nums[r]&1) count+=1;
            while(count>k){
                if(nums[l++]&1) count-=1;
            }
            res+=(r-l+1);
            r++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // use directly two pointer or sliding window i think it should work 
        // no it won't becuase we don't know whether to move l or r 
        // same issue as count the number of binary subarray with sum==k it is exact same , we were doing the same thing there and if you think about it 1 is odd and 0 is even so same method if we apply here it would work

        return sol(nums,k)-sol(nums,k-1);
        
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    int result = sol.numberOfSubarrays(nums, k);
    // Output the result
    cout << "Number of nice subarrays: " << result << endl;
    return 0;
}