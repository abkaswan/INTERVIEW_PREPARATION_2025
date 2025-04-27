#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// easy solution where instead of finding the min and max elements we use directly create new vector current it is easier though
// TC : O(n*2^n) extra n is because we are finding max and min elements which takes O(n) time
// SC : O(n)
// class Solution {
// public:
//     void funo(vector<int>& nums,int k,int i,vector<int>& current,int& count){
//         if(nums.size()==i){
//             if(!current.empty()){
//                 int max_value = *max_element(current.begin(),current.end());
//                 int min_value = *min_element(current.begin(),current.end());
//                 if(max_value+min_value <= k) count+=1; //written inside becuase we are exploring all 2^n possiblities   
//             }
//             return;
//         }
//         // here we are including nums[i] , so when 9->2 it goes it returns to 9 but it can't go to any other call like 5 again because we haven't called that right ? so for that we will need to call again one more recursive call where we exclude the current element
//         current.push_back(nums[i]); 
//         funo(nums,k,i+1,current,count);
//         // here we are excludin nums[i] in current vector
//         current.pop_back();
//         funo(nums,k,i+1,current,count);
//     }
//     int numSubseq(vector<int>& nums, int k) {
//         vector<int> current;
//         int count=0;
//         funo(nums, k, 0, current, count);
//         return count;
//     }
// };
// int main() {
//     vector<int> nums = {3,5,6,7};
//     int k = 9; // your target sum here

//     Solution sol;
//     int result = sol.numSubseq(nums, k);

//     cout << "Result: " << result << endl;

//     return 0;
// }

// solution 2 : where we are trying to find the min and max element without going to trouble of creaing a new vector
// here if we are including the current element we are getting max and min element after comparing it with the current element
// otherwise when we exclude the min and max element stays the same 
// TC : O(2^n) , Branching factor: 2 (include or exclude each of the n elements). Total calls: one per subset → 2𝑛 calls 
// SC : Recursion stack depth: at most n (one frame per element)  O(n)

class Solution {
    public:
        const int MOD = 1e9 + 7;
        void fun(vector<int>& nums,int target,int i,int maxi,int mini,int& count){
            //base case : where we return it , we check min to confirm that at least something was picked
            if(i==nums.size()){
                if(mini!=numeric_limits<int>::max() && maxi+mini <= target) count=(count+1)%MOD; //written inside becuase we are exploring all 2^n possiblities
                return;
            }
            // if we include it the max and min will change it based on nums[i] and if we exclude it , it will reamin the same as previously
            fun(nums,target,i+1,max(maxi,nums[i]),min(mini,nums[i]),count);
            fun(nums,target,i+1,maxi,mini,count);
        }
        int numSubseq(vector<int>& nums, int target) {
            // with the recrursive method 
            int count = 0;
            int mini = numeric_limits<int>::max();
            int maxi = numeric_limits<int>::min();
            fun(nums,target,0,maxi,mini,count);
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