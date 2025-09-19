#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity : O(V+E) = we are going through each node and then each edge throughout like O(V*deg(i)) = O(V+E) and O(E) for going through the edges + O(V) for reversing the result
// space complexity : O(V+E) = we are converting edges to adj so : O(V+E) and we are using visited which is O(V) and the recursion stack can go deep till V so O(V) there
class Solution {
  public:
    void dfs(int node,vector<int>& visited,vector<vector<int>>& adj, vector<int>& res){
        visited[node] = 1;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour,visited,adj,res);
            }
        }
        visited[node]=2;
        res.push_back(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // method 1; dfs 
        // convert to adj list
        vector<vector<int>> adj(V);
        for(auto x : edges){
            int u = x[0], v = x[1];
            adj[u].push_back(v);
        }
        
        // not take one visited array which will have three states 0,1 and 2
        // if we don't want to determine the cycle or not we can do topo sort with only two states 0,1 also
        vector<int> res;
        vector<int> visited(V,0);
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adj,res);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
int main() {
    Solution sol;
    int V = 6;
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    vector<int> result = sol.topoSort(V, edges);
    
    for (int node : result) {
        cout << node << " ";
    }
    
    return 0;
}