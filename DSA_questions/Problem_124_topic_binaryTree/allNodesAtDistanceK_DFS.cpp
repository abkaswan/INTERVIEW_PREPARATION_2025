#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


// 1. buildParent function -->
// Time Complexity:
// Visits every node exactly once.
// For each node, constant work: inserting into unordered_map.
// O(N), where N = number of nodes.

// 📦 Space Complexity:
// Recursive call stack → O(H), where H = height of tree. Worst case skewed tree → O(N), best case balanced → O(log N).
// HashMap stores parent pointers for all nodes → O(N).
// O(N + H), effectively O(N).

// 2. DFSTraversal function -->
// Time Complexity:
// In the worst case, DFS can traverse the entire tree (because you may go down left/right and also climb up via parents).
// Each node is visited at most once, since you mark visited.
// So total → O(N).

// 📦 Space Complexity:
// Recursive stack: in worst case, you could recurse across many nodes, but since visited prevents revisiting, maximum stack depth = O(N) in skewed case.
// visited set → stores each node once → O(N).
// Result vector → at most O(N) if all nodes are at distance k=0.
// O(N) overall.

// Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void buildParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
        if(!root) return;
        if(root->left){
            parent[root->left] = root;
            buildParent(root->left,parent);
        }
        if(root->right){
            parent[root->right] = root;
            buildParent(root->right,parent);
        }
    }
    void DFSTraversal(TreeNode* node,int k,unordered_map<TreeNode*,TreeNode*> &parent,unordered_set<TreeNode*> &visited,vector<int>& result){
        if(!node || visited.count(node)) return;
        visited.insert(node);
        if(k==0){
            // insert it into the result
            result.push_back(node->val);
            return;
        }
        // go left
        DFSTraversal(node->left,k-1,parent,visited,result);
        // go right
        DFSTraversal(node->right,k-1,parent,visited,result);
        // go up 
        if(parent[node]){
            DFSTraversal(parent[node],k-1,parent,visited,result);
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // step1 : build your parent links bedcause you will need it for traversal time -- can do via dfs/bfs both , we are doing dfs here 
        unordered_map<TreeNode*,TreeNode*> mpp;
        buildParent(root,mpp);
        // step 2 : now either do bfs/dfs to traverse the tree -- we are doing dfs here for now.
        unordered_set<TreeNode*> visited;
        vector<int> result;
        DFSTraversal(target,k,mpp,visited,result);
        return result;
        
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution sol;
    vector<int> result = sol.distanceK(root, root->left, 1); // Should return [1, 4, 5]
    
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}