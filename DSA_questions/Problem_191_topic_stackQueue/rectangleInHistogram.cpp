#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// time complexity : O(n) , space complexity : O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // method: monotonic increasing stack , same as trapping rainwater but the only differnece is we are taking increasing stack instead of decreasing , because for the trapping rainwater we needed the popped element to be the smaller one than the surrounding walls , but for this one we need the popped element to be the bigger one so we can calculate the rectangles it can create their windows you know what i mean

        int n = heights.size(),res = 0;
        stack<int> s;
        for(int i = 0;i<=n;i++){
            // for the reaming elements after the loop ends we need to calculate for them also so the right boundary would be n for that and height let's take 0
            int h = (i==n?0:heights[i]);
            while(!s.empty() && heights[s.top()]>h)
            {
                int height = heights[s.top()];
                s.pop();
                // area of the rectangles possilbe for the popped elements , area = height*width
                int width = s.empty()?i:i-s.top()-1;
                res = max(res,height*width);
            }
            s.push(i);
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    int result = sol.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << result << endl; // Expected output: 10
    return 0;
}