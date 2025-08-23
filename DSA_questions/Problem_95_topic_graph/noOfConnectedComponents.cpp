#include <iostream>
#include <vector>
using namespace std;
// Time Complexity: O(n + e)
// Space Complexity:
//   - adj list: O(n + e), but O(n^2) in worst case (dense graph)
//   - visited: O(n)
//   - recursion stack (DFS): O(n)
// Total: O(n + e) normally, O(n^2) worst case (very dense graph)

class Solution {
public:
    /**
     * @param n: the number of vertices
     * @param edges: the edges of undirected graph
     * @return: the number of connected components
     */
    void dfs(int node,vector<int>&visited,vector<vector<int>>&adj){
        visited[node] = 1;
        //dfs meaning go in depth
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour,visited,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>> &edges) {
        vector<int> visited(n,0);
        // make an adj list for the graph right?
        vector<vector<int>> adj(n);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        // continue with DFS OR BFS for traversal maybe 
        for(int i = 0;i<n;i++){
            if(!visited[i])
            {
                count+=1;
                dfs(i,visited,adj); // apply dfs or bfs here , applying dfs for now
            }
        }
        return count;
    }
};
int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    int result = sol.countComponents(n, edges);
    cout << "Number of connected components: " << result << endl;
    return 0;
}