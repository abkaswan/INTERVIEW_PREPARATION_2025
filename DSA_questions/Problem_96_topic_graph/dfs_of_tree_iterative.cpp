#include <iostream>
#include <vector>
using namespace std;
// time complexity O(V + E) where V is the number of vertices and E is the number of edges
// space complexity O(V): O(V) for the visited array , O(V) for the result array and O(V) for the stack in the worst case
class Solution {
  public:
    void dfsFromNodeIterative(int start,vector<int>&visited,vector<vector<int>>&adj,vector<int>& res){
        // we need to take a stack for this right ?
        stack<int> s;
        s.push(start);
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(visited[node]) continue;
            visited[node]=1;
            res.push_back(node);
            
            // we need to add neigbours in reverse as we want to pop which was given first in adj list first
            for(int i = int(adj[node].size())-1;i>=0;i--){
                s.push(adj[node][i]);
                    
            }
            
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
            if(!visited[i]){
                dfsFromNodeIterative(i,visited,adj,res);
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