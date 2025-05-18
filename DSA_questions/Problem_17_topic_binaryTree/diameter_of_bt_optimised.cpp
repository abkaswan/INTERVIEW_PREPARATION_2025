/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <algorithm>
using namespace std;

// structure for TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Time: O(n), as each node’s depth is computed once. Space: O(h) for recursion stack (h = tree height). bottom up approach
class Solution {
public:
    int diam(TreeNode* root,int& diameter)
    {
        if(root == nullptr) return 0;
        int left = diam(root->left,diameter);
        int right = diam(root->right,diameter);
        // now the diameter would be max of left+right and already existing diameter
        diameter = max(left+right,diameter);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diam(root,diameter);
        return diameter;
    }
    // try to do it in one take only : O(n) time think how you can do it.
};
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree is: " << diameter << endl;

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

