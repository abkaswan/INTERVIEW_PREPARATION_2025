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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        if(root == nullptr) return v;
        // now using one stack , and we will have pointer to keep track if we have visited the right subtree or not
        TreeNode* visited = nullptr;
        TreeNode* curr = root;
        while(!s.empty() || curr){
            //keep going left until the curr let's say is not NULL
            if(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            else{
                // first take a peek at the top element inside the stack 
                TreeNode* peek = s.top();
                // we need to check if right subtree is empty or have been visited
                // if not visited visit it , i.e. shift the curr to here , don't pop the top of the stack first we will visit the right subtree
                if(peek->right && visited!=peek->right)
                {
                    curr = peek->right;
                }
                // if right subtree is null or has been visited in that case put the top of the stack in the resultant vector
                else{
                    s.pop();
                    v.push_back(peek->val);
                    visited = peek;
                }
            }
        }
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