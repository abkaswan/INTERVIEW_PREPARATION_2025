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
//using top down approach so takes O(n^2) tc , space complexity is O(h) where h = n in worst case and logn in best case.
class Solution {
public:
    int diam(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int left = diam(root->left);
        int right = diam(root->right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = diam(root->left);
        int right = diam(root->right);
        return max((left+right),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
    // we are taking of max of the path that goes through the root, diameter could be in the left subtree , diameter could be in right subtree , so max of all of those
    // recursive formula for yours : T(n) = T(k) + T(n–1–k) + Θ(n) , worst case : O(n^2) when skewed and best case : O(nlogn)
    // need to learn master theorem also again to calculate complexity from the recurrence relations
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

