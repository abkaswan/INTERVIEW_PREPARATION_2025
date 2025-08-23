#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    // time complexity : 
    // space complexity : 
    bool bfs(int node,int parent, vector<int>&visited, vector<vector<int>>& adj){
        // same way we always do bfs just add the condition where parent!=neighbour
        queue<pair<int,int>> q;
        q.push({node,parent});
        visited[node] = 1;
            
        while(!q.empty()){
            auto [node,parent]=q.front();
            q.pop();
            
            for(auto neighbour:adj[node]){
                
                if(!visited[neighbour])
                {
                    q.push({neighbour,node}); // so we update the parent here.
                    visited[neighbour] = 1;
                }
                else if(parent!=neighbour){
                    //visited and not parent -- cycle detected
                    return true;
                }
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
         // method 2 : use bfs 
        // do the traversal and if we again go to the visited node then return true
        vector<vector<int>> adj(V); 
        // total number of nodes - V
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // step 2 ; do the bfs on the graph , use parent to know that if 
        vector<int> visited(V,0);
        for(int i = 0;i<V;i++){
            if(!visited[i])
                if(bfs(i,-1,visited,adj)) return true;
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