#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// for this you can remove the outer loop also where we are checking !visited[i] , because as per gfg there is only one connected component for the problem but we did it anyway

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // adj list is already given right so just need to do traversal 
        // time complexiy : O(V+E) , here O(V) for outer loop although it won't work when all are visited so it would be O(V)+(the innerloop calculation)
        // for the inner loops: outer loop of queue in worst case would be O(V) and the inner loop of checking neighbour would be O(E) so overall but here also , innerloop calculation : O(V+E)
        // so overall : O(2V+E) == O(V+E)
        
        // space complexity : O(V) =  using res : O(V) + using queue - O(V)
        int n = adj.size();
        vector<int> visited(n,0);
        vector<int> res;
        res.reserve(n);
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                // do the bfs inside it. bfs means level by level so first all the neighbours , then their neighbours like that 
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    res.push_back(node);
                    
                    for(auto&neighbour:adj[node]){
                        if(!visited[neighbour])
                        {    
                            q.push(neighbour);
                            visited[neighbour] = 1; 
                        }
                    }
                }
                
            }
        }
        return res;
    }
};
int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[0].push_back(1);

    adj[1].push_back(0);

    adj[2].push_back(0);
    adj[2].push_back(4);

    adj[3].push_back(0);

    adj[4].push_back(2);

    Solution obj;
    vector<int> res = obj.bfs(adj);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
