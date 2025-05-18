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
    void maxDepthTraverse(TreeNode* root, int len,int& res){
        if(root == nullptr) return;
        res = max(res,len);
        maxDepthTraverse(root->left,len+1,res);
        maxDepthTraverse(root->right,len+1,res);
    }
    int maxDepth(TreeNode* root) {
        // in tree traversals we are doing kind of depth search only so we will take a counter at that time , right 
        int res = 0;
        maxDepthTraverse(root,1,res);
        return res;
    }
};
int main()
{
    Solution sol;
    TreeNode* root = nullptr; // create a binary tree here
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    int depth = sol.maxDepth(root);
    std::cout << "Max depth of binary tree is: " << depth << std::endl;

    return 0;
}
