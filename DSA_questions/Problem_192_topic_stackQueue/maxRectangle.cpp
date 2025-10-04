#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Time Complexity:
- For each of the n rows:
    1. Update the histogram heights for m columns → O(m)
    2. Compute largest rectangle in histogram using monotonic stack → O(m)
- Total per row = O(m + m) = O(m)
- Total for all rows = O(n * m)

Space Complexity:
- heights array → O(m)
- stack used in largest rectangle calculation → O(m)
- Total space = O(m)
*/

class Solution {
public:
    int largestHistogram(vector<int> heights){
        int n = heights.size();
        stack<int> s;
        int res = 0;
        for(int i = 0;i<=n;i++){
            int h = (i==n)?0:heights[i];
            // create increasing monotonic stack
            while(!s.empty() && heights[s.top()]>h){
                int height = heights[s.top()];
                s.pop();

                int width = s.empty()?i:i-s.top()-1;
                res = max(res,height*width);
            }
            s.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // step 1 : build a histogram 
        int n = matrix.size(),m = matrix[0].size(),finalRes = 0;
        vector<int> heights(m,0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]+=1;
                }
                else heights[j] = 0;// if char is '0' we need to reset for sure
            }
            // step 2 : now get he largest rectangle in the histogram problem solved
            finalRes = max(finalRes,largestHistogram(heights));
        }
        return finalRes;
        

    }
};
int main() {
    Solution sol;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    int result = sol.maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << result << endl; // Expected output: 6
    return 0;
}