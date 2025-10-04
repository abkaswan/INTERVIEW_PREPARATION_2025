#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(V+E) = we are going through each node and then each edge throughout like O(V*deg(i)) = O(V+E)
// space complexity : O(V) = we are using visited array of size V and recursion stack can go deep till V so O(V) there
class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& visited){
        if(visited[node]==1) return false; // cycle detected - not safe
        if(visited[node]==2) return true; // already safe

        visited[node] = 1;// in visiting state
        for(auto neighbour : graph[node]){
            if(!dfs(neighbour,graph,visited)) return false;
        }
        visited[node] = 2; //mark it as safe
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // can do dfs , if there are any nodes that are part of the circle or are in a circle we would not include in the answer

        // cycle detection in dfs ? Graph is finite (n nodes).
        // If you keep walking along edges and never hit a terminal, you must eventually revisit a node → that’s a cycle.
        // Therefore, the only two possibilities for a path are:
        //     1. End in a terminal (safe path), or
        //     2. Loop in a cycle (unsafe path).


        // method 1 : dfs
        
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> result;
        for(int i =0;i<n;i++){
            // do the traversal -- let dfs only decide safe or unsafe
            if(dfs(i,graph,visited)){
                result.push_back(i);
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0,1},{5},{},{3,4},{3,1,4},{7,6,4},{4,5,7},{6,7},{6,7},{3,5},{5,6},{3,0,5,6},{3,0,5},{0,5},{5,7},{3,4},{2,3},{3,2},{4,5,6,7},{5,6,7},{6,4,7},{4,7},{4,5,7},{5,6},{6},{7}};
    vector<int> result = sol.eventualSafeNodes(graph);
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
