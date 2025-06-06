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
    // | Approach    | Best for Detecting Asymmetry | Space Complexity |   |
    // | ----------- | ---------------------------- | ---------------- | - |
    // | Stack (DFS) | Deep in the tree             | O(h)             |   |
    // | Queue (BFS) | Near the root                | O(w)             |   |

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<pair<TreeNode*,TreeNode*>> s;
        s.push({root->left,root->right});
        while(!s.empty()){
            auto [root1,root2]=s.top();
            s.pop();
            if(!root1 && !root2) continue;
            if(!root1 || !root2 || root1->val!=root2->val) return false;   
            s.push({root1->left,root2->right});
            s.push({root1->right,root2->left});

        }
        return true;
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
