#include <iostream>
#include <vector>
using namespace std; 
// time complexity : O(V+E) = we are going through each node and then each edge throughout like O(V*deg(i)) = O(V+E) and O(E) for going through the prerequisites
// space complexity : O(V+E) = we are converting edges to adj so : O(V+E) and we are using visited which is O(V) and the recursion stack can go deep till V so O(V) there
class Solution {
public:
    bool dfs(int i , int n , vector<vector<int>>& adj,vector<int>& visited){
        visited[i] = 1; // in visiting state
        for(auto neighbour : adj[i]){
            if(visited[neighbour]==0){
                // means not visited so visit it 
                if(!dfs(neighbour,n,adj,visited)) return false;
            }
            else if(visited[neighbour]==1){
                // means in this visiting state then we can't take this because loop
                return false;
            }
        }
        visited[i] = 2; // visiting done , put in visited state
        return true;

    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // first make the adj list
        vector<vector<int>> adj(n);
        for(auto x : prerequisites){
            auto u = x[0],v = x[1];
            adj[v].push_back(u);
        }

        // now do the topo sort : In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).   
        // method 1 : use dfs 
        vector<int> visited(n,0);
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                if(!dfs(i,n,adj,visited)) return false;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    bool canFinish = sol.canFinish(2, prerequisites);
    cout << (canFinish ? "true" : "false") << endl;
    return 0;
}