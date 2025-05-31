#include <iostream>
#include <vector>
using namespace std;
// Time Complexity: O(n)
// Explanation: We iterate through the vector `height` once in a loop, performing constant time operations for each element.
// Hence, the total time complexity is O(n), where n is the number of elements in the `height` vector.

// Explanation: We use only a few integer variables (`prev1`, `prev2`, `curr`) to store intermediate results,
// and their space usage does not depend on the input size. Therefore, the space complexity is O(1).
// Space Complexity: O(1)
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if(n==1) return 0;
        int prev2 = 0;
        int prev1 = abs(height[0]-height[1])+prev2;
        
        for(int i = 2;i<n;i++){
            int curr = min((abs(height[i-1]-height[i])+prev1),(abs(height[i-2]-height[i])+prev2));
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    vector<int> height = {10, 30, 40, 20}; // example heights
    Solution sol;
    int result = sol.minCost(height);
    cout << "Minimum cost to reach the last stone: " << result << endl;
    return 0;
}

