#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// time complexity : O(V+E) = we are going through each node and then each edge throughout like O(V*deg(i)) = O(V+E) and O(E) for going through the prerequisites
// space complexity : O(V+E) = we are converting edges to adj so : O(V+E) and O(V) for indegree and O(V) for the queue in worst case


// DFS: explicitly looks for a back edge (visiting a node that’s still in the recursion stack).
// BFS (Kahn’s): implicitly detects a cycle when some nodes can never be processed (their indegree never drops to 0)
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // first make the adj list
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto x : prerequisites){
            auto u = x[0],v = x[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        // now do the topo sort : In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).   
        // method 2 : use kahn's algorithm -- bfs
        // add all the indegree : 0 nodes into the queue
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
           }
        }

        int count = 0;
        while(!q.empty()){
            int node = q.front();q.pop();
            count+=1;
            for(int neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        if(count<n){
            return false;
        }
        return true;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    bool canFinish = sol.canFinish(2, prerequisites);
    cout << (canFinish ? "true" : "false") << endl;
    return 0;
}