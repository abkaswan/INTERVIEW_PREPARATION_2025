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
    
    void dfs(TreeNode* root, map<int, map<int, multiset<int>>>& grid,int x,int y){
        if(!root) return;
        // x represent row and y represents column
        grid[y][x].insert(root->val);
        dfs(root->left,grid,x+1,y-1);
        dfs(root->right,grid,x+1,y+1);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // method 1 : use dfs recursive
        
        map<int, map<int,multiset<int>>> grid;
        dfs(root,grid,0,0);

        vector<vector<int>> v;
        for(auto& [col,rowsMap]:grid){
            vector<int> w;
            for(auto& [row,dataSet]:rowsMap){
                for(auto data:dataSet)
                    w.push_back(data);
            }
            v.push_back(std::move(w));
        }
        return v;
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
