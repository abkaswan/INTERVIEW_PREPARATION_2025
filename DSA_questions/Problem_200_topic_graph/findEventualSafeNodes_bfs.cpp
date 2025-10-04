// method 2 : indegree + bfs
        // so using indegree we can know what are the nodes that are not part of the cirlce , but if we do that we won't find all the unsafe node -- our result might have some that were part of the partial circle (or circle path right , we don't want that)
        // so for this we will reverse the graph , make the outdegree = 0 nodes to indegree = 0 nodes, then we will take those nodes and see which nodes they will reach only those nodes will be safe nodes , other might be part of circle directly or indirectly

        // more detailed explanation : 
        /*
        BFS / Indegree Explanation (Eventual Safe Nodes):

        1. Start with terminal nodes (nodes with outdegree = 0) → these are always safe.
        2. Build a reverse graph: for each edge u -> v, add v -> u.
        3. Use a queue to process safe nodes:
        - Pop a node from the queue (it's safe).
        - For each predecessor in the reverse graph:
            - Decrement its outdegree.
            - If outdegree becomes 0 → all outgoing edges lead to safe nodes → mark predecessor safe → push to queue.
        4. Repeat until queue is empty.
        5. Nodes never reaching outdegree 0 are unsafe:
        - This includes nodes in cycles and nodes that eventually lead to cycles (indirectly unsafe).
        6. Collect all safe nodes and sort them.

        Key insight:
        - A node is safe if and only if **every path starting from it eventually reaches a terminal node**.
        - BFS works because only nodes whose all outgoing edges lead to safe nodes are added to the queue.
        - Nodes that point to cycles (even indirectly) never reach outdegree 0 → automatically excluded.

        Time Complexity: O(V + E)
        Space Complexity: O(V + E)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;
        // reverse the graph first and also put indegree , indegree will be +1 in this case if the outdegree of the node is +1 in original graph
        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n,0);
        for(int node = 0;node<n;node++){
            for(auto neighbour : graph[node]){
                reverseGraph[neighbour].push_back(node);
            }
            indegree[node]=graph[node].size();
        }
        // step 2 : check the indegree where it is 0 put them in queue
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i]==0) q.push(i); 
        }

        while(!q.empty()){
            int node = q.front();q.pop();
            result.push_back(node);
            for(auto neighbour : reverseGraph[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        sort(result.begin(),result.end());
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