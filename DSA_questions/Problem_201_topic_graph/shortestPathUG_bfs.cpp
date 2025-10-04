#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// time complexity : O(V+E) and space complexity : O(V) for dist array and O(V) for queue
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // method 1 : do bfs - level by level so that we get the shortest distance 
        int n = adj.size();
        vector<int> dist(n,-1);
        queue<int> q;
        
        q.push(src);
        dist[src]=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto neighbour : adj[node]){
                // if dist is -1 not been visited
                if(dist[neighbour]==-1){
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                }
            }
        }
        return dist;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> adj = {{1,3},{0,2},{1,6},{0,4},{3,5},{4,6},{2,5,7,8},{6,8},{7,6}};
    int src = 0;
    vector<int> res = s.shortestPath(adj, src);

    cout << "Shortest path from source to all other nodes : ";
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
