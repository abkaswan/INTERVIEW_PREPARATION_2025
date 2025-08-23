#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // solution 2 : using min heap , add k elements in a pq and keep it that way only 
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int> , greater<int>> pq;
        int res;
        // now we know how to delete from max heap follow that -- O(klogk)
        for(int i = 0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();

    }
};
int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = sol.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl; // Output: 5
    return 0;
}