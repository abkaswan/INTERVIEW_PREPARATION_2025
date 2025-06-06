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
// Time complexity : O(n) normal bfs -- level by level
// space complexity : O(w) normal dfs , worst case O(n/2) when in the last level there are n/2 elements : perfect binary tree
class Solution {
public:
    // | Approach    | Best for Detecting Asymmetry | Space Complexity |   |
    // | ----------- | ---------------------------- | ---------------- | - |
    // | Stack (DFS) | Deep in the tree             | O(h)             |   |
    // | Queue (BFS) | Near the root                | O(w)             |   |

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root->left,root->right});
        while(!q.empty()){
            auto [root1,root2]=q.front();
            q.pop();
            if(!root1 && !root2) continue;
            if(!root1 || !root2 || root1->val!=root2->val) return false;   
            q.push({root1->left,root2->right});
            q.push({root1->right,root2->left});

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
