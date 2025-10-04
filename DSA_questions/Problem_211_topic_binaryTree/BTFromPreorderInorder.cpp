#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// time complexity : O(N) because we are traversing all the nodes + O(N) for map creation
// space complexity : O(N) for map + O(H) for recursion stack

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
    TreeNode* buildTreeHere(int prestart,int preend,vector<int>& preorder,int instart,int inend,vector<int>& inorder,unordered_map<int,int>& mpp){
        //base condition : when we stop 
        if(prestart>preend || instart>inend) return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);
        // find the position of preorder in inorder map
        int pos = mpp[root->val];
        int numsLeft = pos-instart;

        root->left = buildTreeHere(prestart+1,prestart+numsLeft,preorder,instart,pos-1,inorder,mpp);
        root->right = buildTreeHere(prestart+numsLeft+1,preend,preorder,pos+1,inend,inorder,mpp);

        return root;
    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // method : need to do recursion for this

        // step 1 : save inorder in a map to lookup 
        unordered_map<int,int> mpp;
        for(int i = 0;i<inorder.size();i++)
        {
            mpp[inorder[i]] = i; 
        }

        // step 2 : use the preorder and inorder to make the tree
        int n = preorder.size();
        return buildTreeHere(0,n-1,preorder,0,n-1,inorder,mpp);
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
