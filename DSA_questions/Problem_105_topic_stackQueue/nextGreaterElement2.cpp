#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// time complexity : O(n)--> outer loop - O(2n) , inner loop - O(n) but initially there won't be anything in stack and incremently we might have n elements that we need to pop so overall O(2n+n) it would be 

// space complexity : O(n) - O(n) for stack and O(n) for result vector 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // ok first of all let's do it if there is no circle
        // now think if there is circle allowed like n-1 can find it in 0 and further , but what if the example is like this : 2,1,1,1,1 so normally it would have -1,-1,-1,-1,-1 but by circle it would -1,2,2,2,2 , so how is it possible
        // ok 1,5,4,2,2 is a good example also for our solutin it would be 5,-1,-1,-1,-1 but actually circle allowed then it would be 5,-1,5,5,5 
        stack<int> s;
        vector<int> result(nums.size(), -1);
        int i = 0;
        while(i<2*nums.size()){
            int idx = i%nums.size();
            while(!s.empty() && nums[idx]>nums[s.top()]){
                result[s.top()] = nums[idx];
                s.pop();
            }
            if(i<nums.size())
                s.push(i);
            i++;
        }
        

        
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 2 -1 2
    return 0;
}