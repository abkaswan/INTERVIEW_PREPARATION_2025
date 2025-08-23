// union find : perform operatoins on non-overlapping disjoint subsets
// in union find -- every subset has a parent that it points to , if we merge all connected subsets together and at the end count how many subsets we have in total we will have our answer

// an array of size n , where n is the number of nodes , each value arr[i] is the parent to the node i
// initially : [0,1,2,3...] each node points to itself, now loop over all of the edges given and merge all of the subsets together 

// after this to find out which ones are connected or not , all we need to is follow the paths to count how many unique parents we have , also use path compression where we assign the other nodes in that connected component to have same parent
// path compression -- smooth all of the objects inside our subsets , if we leave and don't do path compression time complexity would increase.

// below is the code for this 

// For the given implementation of UnionFind (Disjoint-Set) with union by size and path compression let:
// n = number of vertices
// m = number of edges
// Time complexity : 
// 1. Initialization for loop : O(n) 
// 2. Processing edges
//    You loop over all $m$ edges, and for each do:
//    * Two `find` calls (one for each endpoint)
//    * Possibly one `union` operation
//    Thanks to path compression + union by size, each find (and hence each union) runs in amortized O(α(n)), where α is the inverse Ackermann function (grows so slowly that α(n)≤4 for any conceivable n).
//    So the total for all unions is
//    O(m·α(n))≈O(m).
// Putting it all together:
// O(n + m·α(n)) ~ O(n + m)

// space complexity : You allocate parent and sz of size n so O(n)

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param n: the number of vertices
     * @param edges: the edges of undirected graph
     * @return: the number of connected components
     */
    int find(int x, vector<int>& parent) {
        // doing path compression here to set the correct parent for x
        return parent[x]==x?x:parent[x]=find(parent[x], parent);
    }
    void unionOfEdge(int a, int b, vector<int>& parent, vector<int>& sz, int& components){
        a = find(a,parent); // find parent of a 
        b = find(b,parent); // find parent of b
        if(a!=b) // if parents are not same then we need to merge the smaller component with the larger one
        {
            if(sz[a]<sz[b]) swap(a,b); // this so that we can merge the smaller one with the larger one
            parent[b] = a;
            sz[a]+=sz[b];
            components--;
        }
    }
    int countComponents(int n, vector<vector<int>> &edges) {
        vector<int> parent(n),sz(n,1);
        int components = n; //initially belive the number of distinct components would be no of nodes n.
        // step1 : make the parent of node , node itself.
        for(int i = 0;i<n;i++){
            parent[i]=i; // this will only work if the nodes are concurrent like 0 to n
        }
        // step2 : try to do union for an edge (u,v) for u and v parent should be the same so call unionOfEdge
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            unionOfEdge(u,v,parent,sz,components);
        }
        return components;
    }
};
int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    int result = sol.countComponents(n, edges);
    cout << "Number of connected components: " << result << endl;
    return 0;
}    