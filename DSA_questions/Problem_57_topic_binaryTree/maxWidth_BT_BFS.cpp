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
// space complexity : O(N) for the queue used in BFS traversal, where N is the number of nodes in the binary tree. In the worst case, the queue can hold all leaf nodes at the last level of the tree , which is N/2.
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // complete binary tree : all nodes are completely filled except the last level . IN last level nodes should be as left as possible , it doesn't matter if it's filled or not.

        // so how would we save this in 1d array , we will take slots like if parent is on index i then children would be at (l,r)=(2*i,2*i+1) this way we will be able to fill all of them in order , even null values we will have space so that we can count , take this hint for this question

        // solution 1. BFS 
        unsigned long long maxWidth = 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            unsigned long long firstIndex=0,lastIndex=0;
            unsigned long long offset = q.front().second;
            for(int i = 0;i<n;i++){
                auto p = q.front();
                TreeNode* root=p.first;
                unsigned long long ind = p.second;
                ind-=offset; // so each index will be like index - offset at the end we need substraction of two indexes so it won't affect our answer
                q.pop();
                
                if(i==0)
                    firstIndex = ind;
                if(i==n-1)
                    lastIndex = ind;

                if(root->left) q.push({root->left,2*ind});
                if(root->right) q.push({root->right,2*ind+1});
            }
            maxWidth = max(maxWidth, lastIndex-firstIndex+1);       
        }
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
