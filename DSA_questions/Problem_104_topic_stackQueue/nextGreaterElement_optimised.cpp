#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // Time:  O(n2+n1) - Process nums2 once with the stack: O(n2) amortized (each element pushed/popped at most once).Fill the answer for nums1 by ans[i] = map[nums1[i]]: O(n1). Total: O(n2 + n1).

    // Space: O(n1+n2) - stack worst-case stores up to O(n2) elements (indices or values).unordered_map (value → nextGreater) stores O(n2) entries in worst case. res uses O(n1) output space.
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // method 2 : using monotonic stack + map 

        // monotonic stack : A stack that maintains a monotone order of values (either strictly increasing or strictly decreasing) from bottom → top. You still use push/pop/top, but you conditionally pop elements while preserving the monotone property when a new value arrives.

        stack<int> s;
        unordered_map<int,int> m;
        for(auto i : nums2){
            while(!s.empty() && i>s.top()){
                    m[s.top()] = i;
                    s.pop();
            }
            s.push(i);

        }
        // for the reamining elements we know that it has no greater element so push -1
        while(!s.empty()){
            m[s.top()] = -1;
            s.pop();
        }

        // now use the nums1 to get the desired values -- can do inplace also in nums2 here instead of using res
        vector<int> res;
        res.reserve(nums1.size());
        for(auto i : nums1){
            res.push_back(m[i]);
        }
        return res;

        // can use in-place like this -->
        // for(int i = 0;i<nums1.size();i++){
        //     int x =nums1[i];
        //     nums1[i] = m[x];
        // }
        // return nums1;
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}