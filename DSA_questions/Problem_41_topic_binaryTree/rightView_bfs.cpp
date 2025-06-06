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
    // time complexity : O(n) go through every element only once
    // space complexity : O(w+h) , if we are considering the resultant vector also , w here refers to the width of the tree
    vector<int> rightSideView(TreeNode* root) {
        // bfs : level order traversal using a queue
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(!q.empty()){
            int n = q.size();
            TreeNode* root = nullptr;
            for(int i = 0;i<n;i++){
                root = q.front();
                q.pop();
                
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);    
            }
            // we will enter the last processed child here
            v.push_back(root->val);
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
    root->right->right = new TreeNode(4);
    vector<int> v = s.rightSideView(root);
    for(auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
