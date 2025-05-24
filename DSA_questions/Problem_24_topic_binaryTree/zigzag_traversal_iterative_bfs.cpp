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
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// structure for TreeNode
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
    // iterative approach where we use queue : avoid reversing , use direct indexing for insertion , tc : O(n) and sc : O(n)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        bool RL = false;

        while(!q.empty()){
            
            int n = q.size();
            v.push_back(vector<int>(n)); //prepare space for current level

            for(int i = 0;i<n;i++){
                int index = RL ? n-i-1:i; // what is the correct index so we won't need to do the indexing here. total size of the 
                
                TreeNode* temp = q.front();
                q.pop();
                
                v.back()[index]=temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            RL = !RL;
        }
        return v;
    }
};
int main()
{
    Solution s;
    TreeNode root(3);
    root.left = new TreeNode(9);
    root.right = new TreeNode(20);
    root.right->left = new TreeNode(15);
    root.right->right = new TreeNode(7);
    vector<vector<int>> res = s.zigzagLevelOrder(&root);
    for (auto &vec : res)
    {
        for (auto &x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
