#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};
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
class Solution {
    public:
        void getAnswer(TreeNode* root, vector<int>& v){
            // recursive solution : left , right , root
            if(root==nullptr) return;
            getAnswer(root->left,v);
            getAnswer(root->right,v);
            v.push_back(root->val);
        }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> v;
            getAnswer(root,v);
            return v;
        }
};

// Helper to build a sample tree:
//        1
//         \
//          2
//         /
//        3
TreeNode* buildSampleTree() {
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(2, n3, nullptr);
    TreeNode* n1 = new TreeNode(1, nullptr, n2);
    return n1;
}

int main() {
    // Build or parse your tree:
    TreeNode* root = buildSampleTree();

    // Compute postorder traversal:
    Solution sol;
    vector<int> post = sol.postorderTraversal(root);

    // Print the result:
    cout << "Post-order traversal: ";
    for (int x : post) {
        cout << x << ' ';
    }
    cout << '\n';

    // Clean up (in production code, consider smart pointers):
    // Here we leak for brevity. In real code, delete all nodes.
    return 0;
}