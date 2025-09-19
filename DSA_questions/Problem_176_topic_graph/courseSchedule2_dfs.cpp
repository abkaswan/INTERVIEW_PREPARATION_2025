#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity : O(V+E) = we are going through each node and then each edge throughout like O(V*deg(i)) = O(V+E) and O(E) for going through the prerequisites + O(V) for reversing the result
// space complexity : O(V+E) = we are converting edges to adj so : O(V+E) and we are using visited which is O(V) and the recursion stack can go deep till V so O(V) there 
class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj, vector<int>& visited,vector<int>& result){
        visited[i] = 1; // in visiting state or in current dfs stack
        for(auto neighbour: adj[i]){
            if(!visited[neighbour]){
                if(!dfs(neighbour,adj,visited,result)) return {};
            }
            else if(visited[neighbour]==1)
            {
                // there is a cycle return it
                return false;
            }
        }
        visited[i] = 2; // mark it as visited
        result.push_back(i);
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // first of all make a adj list for thist
        // because an edge for (j,i) would be i->j according to the question
        vector<vector<int>> adj(n);
        for(auto &x : prerequisites){
            auto j = x[0], i = x[1];
            adj[i].push_back(j);
        }
        // method 1 : do a dfs for this 
        vector<int> visited(n,0);
        vector<int> res;
        // do this loop so that if there are connected components they gets traverserd
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                if(!dfs(i,adj,visited,res)) return {};
            }
        }
        reverse(res.begin(),res.end());
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