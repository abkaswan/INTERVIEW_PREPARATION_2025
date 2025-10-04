#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

// Time Complexity: O(V + E)
// - Topological sort (DFS): O(V + E)
// - Relaxing all edges once: O(E)

// Space Complexity: O(V + E)
// - Adjacency list: O(V + E)
// - Distance vector: O(V)
// - indegree array: O(V)
// - Topological order list (topoList): O(V)

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // method 2 : topo sort and then relax each branch once -- topo sort with indegree method - shortestPathDAG_topoSort_bfs_optimised
        // in this method we geth the topo sort so we know each node in order came first , came first in tree , so if we process all the outgoing edges then at the time we reach for example : 3->4 we have already final vaule for 3 then we don't know to re-evaluate or relax this edge again we will get the value for this branch for sure , maybe not for 4 but for the edge we know the final value that will be coming
        // O(V+E)  --- in the file shortestPathDAG_topoSort_bfs and shortestPathDAG_topoSort_dfs
        
        // 1. doing topo sort
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indegree(V,0);
        
        for(int i = 0;i<E;i++){
            int u = edges[i][0], v = edges[i][1] , weight = edges[i][2];
            adj[u].push_back({v,weight});
            indegree[v]++;
        }
        queue<int> q;
        vector<int> topoList;
        // put all the elements with indegree 0 in queue to process them
        for(int i = 0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();q.pop();
            topoList.push_back(node);
            for(auto [v,w]:adj[node]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        
        // 2. now relax the edges and fill dist
        vector<int> dist(V,INT_MAX);
        dist[0] = 0;
        for(int u : topoList){
            if(dist[u]!=INT_MAX){ // to ensure only nodes reachable from 0 are processed
                for(auto[v,w]:adj[u]){
                    if(dist[v]>dist[u]+w){
                        dist[v] = dist[u]+w;
                    }
                }
            }
        }
        
        // 3. return the result
        for(int i = 0; i<V; i++)
            if(dist[i] == INT_MAX) dist[i] = -1;
        return dist;
    }
};
int main() {
    int V = 6, E = 7;
    vector<vector<int>> edges = {{0,1,5},{0,2,3},{1,3,6},{1,2,2},{2,4,4},{2,5,7},{2,3,1},{5,4,-1}};
    Solution s;
    vector<int> res = s.shortestPath(V,E,edges);
    for(auto x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}