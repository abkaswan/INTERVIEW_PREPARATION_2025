#include <iostream>
#include <vector>
using namespace std;
// time complexity O(nlog(max(nums[i]))) and space complexity O(1) 
int findgcd(int a,int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        // need to do for adjacent numbers so no issue with this method ig

        // make nums behave like a stack here
        for(int i=0;i<n;i++){
            nums[k++] = nums[i];
            while(k>1){
                int gcd = findgcd(nums[k-1],nums[k-2]);
                if(gcd==1) break;
                // otherwise take lcm , so divide first multiply later to avoid overflow
                long long lcm = 1LL*nums[k-1]/gcd*nums[k-2];
                nums[k-2] = lcm;
                k--; // pop once right so k will have at the place of k-1
            }
            
            
        }
        nums.resize(k);
        return nums;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {6,4,3,2,7,6,2};
    vector<int> result = sol.replaceNonCoprimes(nums);
    for(int num : result){
        cout << num << " ";
    }
    return 0;
}