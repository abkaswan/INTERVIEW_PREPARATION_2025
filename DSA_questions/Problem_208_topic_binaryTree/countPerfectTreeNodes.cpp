#include <iostream>
#include <cmath>
using namespace std;
// time complexity: O(h) where h is the height of the tree and space complexity: O(1)
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
        int h = getHeight(root);
        return (1<<h)-1; //2^h-1 -- number of nodes in perfect binary tree
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    cout << "Number of nodes: " << sol.countNodes(root) << endl;
    return 0;
}
