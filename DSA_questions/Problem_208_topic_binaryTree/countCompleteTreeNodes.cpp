#include <iostream>
#include <cmath>
using namespace std;
// time complexity: O((log n)^2) where h is the height of the tree -- because getHeight is O(h) and we are calling it log n times -- log n times because we are reducing the tree height by 1 in each recursive call
// space complexity: O(1)
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
    int getHeight(TreeNode* root){
        int h = 0;
        while(root){
            root = root->left;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        // now for the compelete binary tree we need to check 
        // 1. if left is perfect binary tree then great go to right
        // 2. else go to the left because there is some missing node in the left subtree
        
        int lefth = getHeight(root->left);
        int righth = getHeight(root->right);
        if(lefth == righth){
            // total nodes : leftSubtree height(usign perfect tree formula)+root+recurse on right
            return (1<<lefth)+countNodes(root->right);
        }
        else{
            // total nodes : rightSubtree height + root + recurse on left
            return (1<<righth)+countNodes(root->left);
        }
        
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    Solution sol;
    cout << "Number of nodes: " << sol.countNodes(root) << endl;
    return 0;
}