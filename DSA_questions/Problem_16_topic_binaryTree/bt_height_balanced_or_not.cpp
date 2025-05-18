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
#include <vector>
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

class Solution {
public:
    int isBalancedTraverse(TreeNode* root){
        if(root==nullptr) return 0;
        int left = isBalancedTraverse(root->left);
        if(left == -1) return -1; // to end it early and if you don't use it , it masks the error that we are trying to send
        int right = isBalancedTraverse(root->right);
        if(right==-1) return -1; // to end it early and if you don't use it , it masks the error that we are trying to send
        if(abs(left-right)>1) return -1;
        // return subtree height though here otherwise how would we know
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        // we can use postorder traversal for that and see if the difference that comes up is greater than 1 somehow 
        return isBalancedTraverse(root)!=-1;
    }
};

int main()
{
    Solution solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    bool isBalanced = solution.isBalanced(root);
    cout << (isBalanced ? "Yes" : "No") << endl;

    return 0;
}
