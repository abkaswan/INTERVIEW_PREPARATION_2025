#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// time complexity : O(V+E) = we are going through each node and then each edge throughout like O(V*deg(i)) = O(V+E) and O(E) for going through the prerequisites
// space complexity : O(V+E) = we are converting edges to adj so : O(V+E) and we are using indegree which is O(V) and O(V) for the queue in worst case and O(V) for result
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // method 2; bfs or kahn's algorithm
        // convert to adj list and take indegree for them 
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        for(auto x : edges){
            int u = x[0], v = x[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        
        queue<int> q;
        vector<int> res;
        for(int i = 0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        if(res.size()<V) return {};
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