#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// time complexity : O(V+E)
// space complexity : O(V) for color array and O(V) for queue in worst case

// method : two coloring approach using bfs
// Keep a color[] array, initialized to -1 (uncolored).
//         For each node u:
//             If u is uncolored, assign it a color (say 0) and start DFS/BFS from it.
//         For each neighbor v:
//             If v is uncolored → assign opposite color of u.
//             If v already has the same color as u → conflict → return false.
// If you finish processing all nodes without conflict → return true.


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // total nodes
        int n = graph.size();
        // in case there is connected components we will do a for loop
        vector<int> color(n,-1);// intially nothing is colored , taking 0 and 1 two colors for this one
        for(int i = 0;i<n;i++){
            if(color[i]!=-1) continue; // already visited in some bfs

            queue<int> q;
            q.push(i);
            color[i] = 0; // color it with 0 
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto neighbour : graph[node]){
                    if(color[neighbour]==-1){
                        color[neighbour] = 1-color[node];// assign the opposite color
                        q.push(neighbour);
                    }
                    else if(color[neighbour]==color[node]) return false;
                    
                }
            }
            
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };
    bool result = sol.isBipartite(graph);
    cout << (result ? "Graph is bipartite" : "Graph is not bipartite") << endl;
    return 0;
}