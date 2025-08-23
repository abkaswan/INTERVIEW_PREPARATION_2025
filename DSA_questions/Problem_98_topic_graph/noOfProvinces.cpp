#include <iostream>
#include <vector>
using namespace std;



// Time complexity: O(n2).
    // Initializing the visit array takes O(n) time.
    // The dfs function visits each node once, which takes O(n) time because there are n nodes in total. From each node, we iterate over all possible edges using isConnected[node] which takes O(n) time for each visited node. As a result, it takes a total of O(n2) time to visit all the nodes and iterate over its edges.
// Space complexity: O(n).
    // The visit array takes O(n) space.
    // The recursion call stack used by dfs can have no more than n elements in the worst-case scenario. It would take up O(n) space in that case
// you can solve ti using bfs and union - find algo also like we did earlier 


class Solution {
public:
    void dfs(int i,vector<int>&visited,vector<vector<int>>&isConnected){
        int n = isConnected.size();
        visited[i+1] = 1;

        // and wherever we have isConnected[i][j]=1 we need to traverse that also as we are doing dfs
        for(int j = 0;j<n;j++){
            if(isConnected[i][j]==1 && !visited[j+1]){
                dfs(j,visited,isConnected);
            }
        }
    }
    //given graph is index 1 so we are using visited[i+1] and all 
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        // basically need to give total connected components and we have been given adj matrix
        int n = isConnected.size();
        vector<int> visited(n+1,0);
        int count = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i+1]){
                count+=1;
                dfs(i,visited,isConnected);
            }
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    int result = sol.findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl; // Expected output: 2
    return 0;
}