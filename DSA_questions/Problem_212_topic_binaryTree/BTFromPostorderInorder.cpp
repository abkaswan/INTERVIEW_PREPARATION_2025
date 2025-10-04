#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    TreeNode* buildTreeHere(int poststart,int postend,vector<int>& postorder,int instart,int inend,vector<int>& inorder,unordered_map<int,int>& mpp){
        if(poststart>postend || instart>inend) return NULL;

        TreeNode* root = new TreeNode(postorder[postend]);

        // find the pos for the inorder
        int pos = mpp[root->val];
        int numsLeft = pos-instart;

        root->left = buildTreeHere(poststart,poststart+numsLeft-1,postorder,instart,pos-1,inorder,mpp);
        root->right = buildTreeHere(poststart+numsLeft,postend-1,postorder,pos+1,inend,inorder,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // step 1 : store the inorder in some map to access it later
        unordered_map<int,int> mpp;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]] = i;
        }

        // step2 : build the tree -- we start from the last for the postorder unlike preorder because root is at the last
        return buildTreeHere(0,n-1,postorder,0,n-1,inorder,mpp);

    }
    void printInorder(TreeNode* node) {
        if (!node) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    }
};
int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);

    // print the tree in inorder to verify
    s.printInorder(root);
    cout << endl;
    
    return 0;
}
