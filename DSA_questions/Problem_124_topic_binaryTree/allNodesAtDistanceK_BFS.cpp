#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// Function 1: buildParent(root, mpp)
// You perform a BFS traversal of the entire tree.
// For each node, you insert at most one entry into the map for its left child and one for its right child.
// Time Complexity --->
// Visiting all n nodes → O(n)
// Each push/pop to queue and map insertion is O(1) average → total still O(n)

// Space Complexity --->
// Queue stores up to O(n) in the worst case (e.g., complete binary tree last level).
// Map mpp stores up to O(n) parent pointers.
// So total → O(n)

// Function 2: BFSTraversal(target, k, parent)
// This is another BFS, but this time starting from the target node.
// Each node is enqueued at most once (because of the visited set).
// Time Complexity --->
// Each node is processed once → O(n) in worst case (when k is large enough to reach all nodes).
// Space Complexity --->
// Queue can hold up to O(n) nodes in worst case.
// visited set can store up to O(n) nodes.
// So total → O(n)

// ✅ Final Answer:
// Time Complexity: O(n)
// Space Complexity: O(n)

// Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void buildParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mpp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right] = node;
                q.push(node->right);
            } 
        }
    }
    vector<int> BFSTraversal(TreeNode* target,int k,unordered_map<TreeNode*,TreeNode*> &parent){
        
        unordered_set<TreeNode*> visited;
        
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        // to see the what level we are at
        int level = 0;

        while(!q.empty()){

            int size = q.size();
            if(level == k){
                vector<int> v;
                while(!q.empty()){
                    v.push_back(q.front()->val);
                    q.pop();
                }
                return v;
            }

            while(size--){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                } 
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent[node] && !visited.count(parent[node])){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            level++;
        }
        return {};
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // step1 : build your parent links bedcause you will need it for traversal time -- can do via dfs/bfs both , we are doing bfs here 
        unordered_map<TreeNode*,TreeNode*> mpp;
        buildParent(root,mpp);
        // step 2 : now either do bfs/dfs to traverse the tree -- we are doing bfs here for now.
        return BFSTraversal(target,k,mpp);
        
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