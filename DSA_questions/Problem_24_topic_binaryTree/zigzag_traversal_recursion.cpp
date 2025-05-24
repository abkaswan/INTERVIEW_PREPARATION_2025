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
    // generally bfs is solved using iterative but recursive approach , tc : O(n),sc : O(n)
    void zigzag(TreeNode* root,vector<vector<int>>& v,int level){
        if(root==nullptr) return;
        if (level >= v.size()) { // we need to have some space first to push something right
            v.push_back({});
        }
        v[level].push_back(root->val);
        zigzag(root->left,v,level+1);
        zigzag(root->right,v,level+1);

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        zigzag(root,v,0);
        for(int i = 1;i<v.size();i+=2)
        {
            reverse(v[i].begin(),v[i].end());
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
