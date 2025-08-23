#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// time complexity : O(V+E) = we are going through each node and then each edge throughout like O(V*deg(i)) = O(V+E)
// space complexity : O(V+E) = we are converting edges to adj so : O(V+E) and we are using visited which is O(V) and the recursion stack can go deep till V so O(V) there ?
    
class Solution {
  public:
    bool dfs(int node,int parent, vector<int>&visited, vector<vector<int>>& adj){
        visited[node] = 1;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour,node,visited,adj)) return true;
            }
            else if(neighbour!=parent) // if visited and not parent -- that means cycle
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
         // method 1 : use dfs 
        // do the traversal and if we again go to the visited node then return true
        vector<vector<int>> adj(V); 
        // total number of nodes - V
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // step 2 ; do the dfs on the graph , use parent to know that if 
        vector<int> visited(V,0);
        for(int i = 0;i<V;i++){
            if(!visited[i])
                if(dfs(i,-1,visited,adj)) return true;
        }
        return false;
        
        
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