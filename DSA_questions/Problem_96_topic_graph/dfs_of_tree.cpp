#include <iostream>
#include <vector>
using namespace std;
// time complexity O(V + E) where V is the number of vertices and E is the number of edges
// space complexity O(V): O(V) for the visited array , O(V) for the result array and O(V) for the recursion stack in the worst case
class Solution {
  public:
    void dfsFromNode(int node,vector<int>&visited,vector<vector<int>>&adj,vector<int>& res){
        visited[node]=1;
        res.push_back(node);
        //dfs basically means going in depth : so if we go to adj list and see if it is not visited then visit it 
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]) dfsFromNode(neighbour,visited,adj,res);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // so we are given a adj list already 
        // step 1 : find total number of nodes 
        int n = adj.size();
        // step 2 : declare visited and use it to traverse
        vector<int> visited(n,0);
        vector<int> res;
        res.reserve(n);// avoid reallocation
        for(int i = 0;i<n;i++){ 
            // we can skip this for loop and directly do dfsFromNode(0,visited,adj,res) but just added to remind myself that there could be more components that are not connected
            if(!visited[i]){
                dfsFromNode(i,visited,adj,res);
            }
        }
        return res;
    }
};
int main() {
    // Example usage
    Solution sol;
    vector<vector<int>> adj = {
        {1, 2},    // Node 0 is connected to nodes 1 and 2
        {0, 3},    // Node 1 is connected to nodes 0 and 3
        {0},       // Node 2 is connected to node 0
        {1}        // Node 3 is connected to node 1
    };
    
    vector<int> result = sol.dfs(adj);
    
    for(int node : result) {
        cout << node << " ";
    }
    
    return 0;
}