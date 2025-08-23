#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
    }
};
int main() {
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    bool hasCycle = sol.isCycle(V, edges);
    cout << "Graph contains cycle: " << (hasCycle ? "Yes" : "No") << endl;
    return 0;
}