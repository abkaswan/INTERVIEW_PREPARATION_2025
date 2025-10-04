#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// time complexity : O(n) , space complexity : O(n)
class Solution {
public:
    int trap(const vector<int>& height) {
        int n = height.size();
        long long res = 0;
        //method 3 : using the stack , the stack will be monotonic decreasing stack 
        // now if we pop any element that means it was smaller than below it and what we are gonna add , so those two will be conidered left and right walls for that particular element and we will take smaller of them and calculate the results
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            // while current bar is higher than stack top -> we can trap water
            while (!s.empty() && height[i] > height[s.top()]) {
                int bottom = s.top();
                s.pop();
                if (s.empty()) break; // no left wall

                int left = s.top();
                int width = i - left - 1;
                int boundedHeight = min(height[i], height[left]) - height[bottom];
                res += 1LL * width * boundedHeight;
            }
            s.push(i);
        }
        return (int)res; // fits constraints
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(height) << endl; // Output: 6
    return 0;
}