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
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
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
    int maxSum(TreeNode* root,int& res){
        // if(root->left==nullptr && root->right==nullptr) return root->val;
        if(root==nullptr) return 0;
        int leftSum = max(0,maxSum(root->left,res)); //if any branch is giving negative values we discard that branch completely
        int rightSum = max(0,maxSum(root->right,res)); //same here
        res = max(res,leftSum+rightSum+root->val);
        // return leftSum+rightSum+root->val; here we should give one branch upward not the whole sum for left and right you got it right that's why your statement is wrong
        return root->val+max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxSum(root,res);
        return res;
    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout<<"max path sum is : "<<s.maxPathSum(root)<<endl;
    return 0;
}
