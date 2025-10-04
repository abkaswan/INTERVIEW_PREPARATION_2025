// time compelxity : 
// Step 1 : The work is in relaxing edges. For each DFS call on node u, we check its outgoing edges (u → v, w).
// So the cost is proportional to “number of times edges get scanned”.

// Step 2: How many times can an edge get scanned?
// In DFS-propagation → edge (u→v) might be scanned every time dist[u] improves.
// Why? Because whenever dist[u] improves, we re-DFS from u → recheck all (u→v) edges.

// Step 3: How many times can dist[u] improve? At most V−1 times.
// Why? In a graph with V vertices, the longest simple path has at most V−1 edges.
// Each time dist[u] improves, it must be through a strictly shorter path (fewer or lighter edges).
// So in the absolute worst case, a node’s distance could be updated once per extra edge along some longer path.
// example : 
// 0 → 1 (100)
// 0 → 2 (200)
// 0 → 3 (300)
// 0 → 4 (400)
// 1 → 2 (10)
// 2 → 3 (10)
// 3 → 4 (10)

// so first 0->1->2->3->4 then 0->2->3->4 then 0->3->4 then 0->4 so V-1
// Each vertex u can trigger ≤ (V−1) improvements.
// Each improvement of u → re-scan all outgoing edges from u.
// If deg(u) = number of outgoing edges from u, then worst case:
// work(u) ≤ (V−1) * deg(u)
// Total work ≤ (V−1) * Σ deg(u)
//           = (V−1) * E
//           = O(V * E)

// comparing with normal dfs with visited array 
// | DFS Type                | Node revisits?        | Edge revisits? | Complexity            |
// | ----------------------- | --------------------- | -------------- | --------------------- |
// | Normal DFS with visited | Never                 | Once per edge  | `O(V + E)`            |
// | DFS-propagation         | Yes, if dist improves | Multiple times | `O(V * E)` worst case |

// so finally method 1 --> time complexity : O(V+E) and space complexity : Adjacency list: O(V + E) Distance vector: O(V) Recursive stack: O(V) Total: O(V + E)

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
  public:
    void dfs(int node,vector<vector<pair<int,int>>>& adj,vector<int>& dist){
        for(auto nei : adj[node]){
            auto [neiNode,neiWeight] = nei;
            if(dist[neiNode]>dist[node]+neiWeight){
                dist[neiNode] = dist[node]+neiWeight;
                dfs(neiNode,adj,dist);
            }
        }
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // method 1 : normal dfs -- in file shortestPathDAG_dfsPropogation
        // here you are going to each path udpating it and if later better path is there you re-evaluate the subtree again , so you are repeating the work 
        // relaxing a branch is re-evaluating it , if the branch 3->4 is there and you are going again for it because the value of 3 chagned then this is re-work
        // O(V*E) repeating work : Worst-case behavior can approach O(V * E) (similar to Bellman-Ford doing repeated relaxations), so it can be much slower on pathological DAGs.
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0;i<E;i++){
            int u = edges[i][0], v = edges[i][1] , weight = edges[i][2];
            adj[u].push_back({v,weight});
        }
        vector<int> dist(V,INT_MAX);
        dist[0] = 0;
        dfs(0,adj,dist);
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
