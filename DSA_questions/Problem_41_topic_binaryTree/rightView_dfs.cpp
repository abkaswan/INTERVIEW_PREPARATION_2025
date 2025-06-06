#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//  Definition for a binary tree node.
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
    // Time complexity : O(n) each node is visit only once , dfs
    // space complexity : O(2h) , O(h) for saving the result in vector , and O(h) for recursion stack
    void dfs(TreeNode* root,vector<int>&v,int row){
        if(!root) return;
        if(row == v.size()) v.push_back(root->val);
        dfs(root->right,v,row+1);
        dfs(root->left,v,row+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        // dfs : using a vector
        vector<int> v;
        dfs(root,v,0);        
        return v;
    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> v = s.rightSideView(root);
    for(auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
