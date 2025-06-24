#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Time complexity : O(N) where N is the number of nodes in the binary tree.
// Space complexity : O(H+H) ~ O(2N) in worst case , for the unordered_map used in DFS traversal O(H) and also recursion stack space is taking O(H) where H is the height of the tree.
class Solution {
public:
    void dfs(TreeNode* root, int level,unordered_map<int,unsigned long long>& fil,unsigned long long ind,unsigned long long &maxWidth){
        if(!root) return;
        if(!fil.count(level)) fil[level]=ind;
        
        auto offset = fil[level];
        maxWidth = max(maxWidth,ind-offset+1);
        
        dfs(root->left,level+1,fil,2*(ind-offset),maxWidth);
        dfs(root->right,level+1,fil,2*(ind-offset)+1,maxWidth);
    }
    int widthOfBinaryTree(TreeNode* root) {
        // complete binary tree : all nodes are completely filled except the last level . IN last level nodes should be as left as possible , it doesn't matter if it's filled or not.

        // so how would we save this in 1d array , we will take slots like if parent is on index i then children would be at (l,r)=(2*i,2*i+1) this way we will be able to fill all of them in order , even null values we will have space so that we can count , take this hint for this question

        // solution 2. DFS , here fil is vector for firsrt index on each level
        unordered_map<int,unsigned long long> fil;
        unsigned long long maxWidth = 0;
        dfs(root,0,fil,0,maxWidth); 
        return maxWidth;
    }
};
int main() {
    // Example usage for widthOfBinaryTree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;
    int width = solution.widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree: " << width << endl;

    return 0;
}
