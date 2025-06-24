#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Time complexity: O(n) where n is the number of nodes in the tree and space complexity: O(h) where h is the height of the tree due to recursion stack.
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &res){
        if(!root) return false;

        bool left = dfs(root->left,p,q,res);
        bool right = dfs(root->right,p,q,res);
        
        // if left subtree and right subtree both found the p and q then the root is the result now.
        if(left && right) res = root;
        // if either one of them found either p or q , then we check what if the root is the other one ( let;s say left subtree has p then we check that can the root be q now if yes return true)
        if(left || right){
            if(root==p || root==q) res = root; 
        }

        // if root is p or q then we return true upwards in the tree.
        if(root==p || root==q) return true;
        return left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
        dfs(root,p,q,res);
        return res;
    }
};

int main() {
    Solution solution;
    
    // Example tree:
    //      3
    //     / \
    //    5   1
    //   /|   |\
    //  6 2   0 8
    //    |\
    //    7 4

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* p = root->left; // node with value 5
    TreeNode* q = root->right; // node with value 1

    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    if (lca) {
        std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;
    } else {
        std::cout << "Lowest Common Ancestor not found." << std::endl;
    }

    // Clean up the allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}

