// method : two coloring approach using dfs
// Keep a color[] array, initialized to -1 (uncolored).
//         For each node u:
//             If u is uncolored, assign it a color (say 0) and start DFS from it.
//         In DFS:
//             For each neighbor v:
//                 If v is uncolored → assign opposite color of u and recurse DFS on v.
//                 If v already has the same color as u → conflict → return false.
// If you finish processing all nodes without conflict → return true.
#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(V+E)
// space complexity : O(V) for color array and O(V) for recursion stack in worst case

class Solution {
public:
    bool dfsTraversal(int i , vector<vector<int>>& graph, vector<int>& color,int currentColor){
        color[i] = currentColor;

        for(int nei : graph[i]){
            if(color[nei]==-1){
                color[nei] = 1-color[i];
                // assign opposite color and recurse
                // returning false early because conflict found in depper cell
                if(!dfsTraversal(nei,graph,color,1-currentColor)) return false;

            }
            else if(color[nei]==currentColor) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // total nodes
        int n = graph.size();
        // in case there is connected components we will do a for loop
        vector<int> color(n,-1);// intially nothing is colored , taking 0 and 1 two colors for this one
        for(int i = 0;i<n;i++){
            if(color[i]==-1){
                if(!dfsTraversal(i,graph,color,0)) return false;
            } 
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };
    bool result = sol.isBipartite(graph);
    cout << (result ? "Graph is bipartite" : "Graph is not bipartite") << endl;
    return 0;
}