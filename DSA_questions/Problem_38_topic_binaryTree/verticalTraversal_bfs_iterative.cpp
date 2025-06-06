#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>

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
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // method 2 : use bfs iterative
        map<int, map<int,multiset<int>>> grid;
        queue<tuple<TreeNode*,int,int>> q;
        q.push({root,0,0});
        while(!q.empty()){
            auto [root,col,row]=q.front();
            q.pop();
            // also we need to store it in grid right 
            grid[col][row].insert(root->val);
            if(root->left) q.push({root->left,col-1,row+1});
            if(root->right) q.push({root->right,col+1,row+1});
        }
        vector<vector<int>> res;
        for(auto& [col,rowMap]:grid){
            vector<int> v;
            for(auto& [row,dataMap]:rowMap){
                for(int i:dataMap){
                    v.push_back(i);
                }
            }
            res.push_back(std::move(v));
        }
        return res;
    }
};
int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> res = s.verticalTraversal(root);
    for(auto &v : res)
    {
        for(auto &x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
