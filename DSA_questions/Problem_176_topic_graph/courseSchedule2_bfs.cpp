// TOPOLOGICAL SORT USING INDEGREE (LOGIC EXPLANATION)

// 1. Directed Graph:
//    - In a directed graph, every edge points from one node to another.
//    - For example: A → B means A must come before B.

// 2. Indegree:
//    - The indegree of a node = number of incoming edges to that node.
//    - Example: If C has edges from A and B (A → C, B → C), indegree(C) = 2.
//    - Interpretation: "How many prerequisites does this node have?"

// 3. Why Indegree is Useful:
//    - A node with indegree = 0 has no prerequisites → it can be processed immediately.
//    - Once we "process" a node, we remove its outgoing edges.
//    - This reduces the indegree of its neighbors (since one prerequisite is completed).
//    - If a neighbor’s indegree becomes 0, it means all its prerequisites are done, so it can now be processed.

// 4. Step-by-Step Process (Kahn’s Algorithm):
//    a) Calculate indegree of every node.
//    b) Push all nodes with indegree = 0 into a queue.
//    c) While queue is not empty:
//       - Remove a node from the queue → add it to the result.
//       - For each neighbor of that node:
//         → reduce neighbor’s indegree by 1.
//         → if neighbor’s indegree becomes 0, push it into the queue.
//    d) Repeat until all nodes are processed.

// 5. Example:
//    Graph Edges: A → B, A → C, B → D, C → D

//    Indegree:
//      A = 0
//      B = 1 (from A)
//      C = 1 (from A)
//      D = 2 (from B, C)

//    Steps:
//      Start Queue = [A]
//      Process A → result = [A]
//        Reduce indegree(B) = 0 → push B
//        Reduce indegree(C) = 0 → push C
//      Queue = [B, C]
//      Process B → result = [A, B]
//        Reduce indegree(D) = 1
//      Process C → result = [A, B, C]
//        Reduce indegree(D) = 0 → push D
//      Process D → result = [A, B, C, D]

//    Final Order: [A, B, C, D] or [A, C, B, D]

// 6. Key Idea:
//    - Indegree tells us "how many things must happen before this node".
//    - When indegree = 0, the node is free to execute.
//    - Topological sort is just repeatedly picking nodes with indegree = 0.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// time complexity : O(V+E) = we are going through each node and then each edge throughout like O(V*deg(i)) = O(V+E) and O(E) for going through the prerequisites
// space complexity : O(V+E) = we are converting edges to adj so : O(V+E) and O(V) for indegree and O(V) for the queue in worst case and O(V) for result
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // first of all make a adj list for thist
        // because an edge for (j,i) would be i->j according to the question
        
        // method 2 : do a bfs for this 
        // compute in-degree for every node 
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &x : prerequisites){
            auto j = x[0], i = x[1];
            adj[i].push_back(j);
            indegree[j]++;
        }
        vector<int> res;
        // push all nodes with indegree zero into the queue
        queue<int> q;
        for(int i = 0;i<n;i++){
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
        if(res.size()<n) return {};
        return res;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> prerequisites = {{1,0},{2,1},{3,2}};
    vector<int> order = sol.findOrder(4, prerequisites);
    for(int i : order) {
        cout << i << " ";
    }
    return 0;
}