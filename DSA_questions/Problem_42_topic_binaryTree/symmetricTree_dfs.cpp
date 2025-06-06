#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Time complexity : O(n) normal dfs
// space complexity : O(h) normal dfs , worst case O(n) skewed tree and O(logn) for balanced tree
class Solution {
public:
    bool dfs(TreeNode* root1, TreeNode* root2){
        if(!root1 || !root2) return root1==root2;
        if(root1->val!=root2->val) return false;
        return (root1->val==root2->val)&&dfs(root1->left,root2->right) && dfs(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        // step 1: send the root->left and root->right as the root and check if , root1->left == root2->right and root1->right == root2->left
        if(!root) return true;
        return dfs(root->left,root->right);
    }
};
int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << s.isSymmetric(root) << endl;
    return 0;
}
