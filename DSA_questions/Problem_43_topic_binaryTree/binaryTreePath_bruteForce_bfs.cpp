#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// N = total nodes ,h = tree height (≤ N, typically O(logN)) ,W = maximum width of any level, M = number of leaves
// | Measure         | Complexity                                            |
// | --------------- | ----------------------------------------------------- |
// | Time            | O(N.h) → worst O(N^2), average O(NlogN) |
// | Auxiliary Space | O(W.h) (queue)                                |
// | Output Space    | O(M.h) (result strings)                       |


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        queue<pair<TreeNode*,string>> q;
        q.push({root,to_string(root->val)});
        while(!q.empty()){
            auto [root,s] = q.front();
            q.pop();
            if(!root->left && !root->right){
                v.push_back(s);
            }
            if(root->left) q.push({root->left,s+"->"+to_string(root->left->val)});
            if(root->right) q.push({root->right,s+"->"+to_string(root->right->val)});
        }
        return v;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    vector<string> v = s.binaryTreePaths(root);
    for(auto& i:v){
        cout<<i<<endl;
    }
    return 0;
}
