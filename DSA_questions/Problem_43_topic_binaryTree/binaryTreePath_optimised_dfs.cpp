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
// Time: O(N)+O(M⋅h), here M is number of nodes , h is tree height and N is total nodes so overall if there is a bushy tree with M = O(N) and h = O(logn) it would be O(NlogN) at max , worst case it is h = N , M = 1 so O(N)
// Auxiliary space: O(h) (call stack) + O(h) path buffer(one string or vector of length up to h).
// Output space: O(M⋅L) to store all the root-to-leaf paths.

class Solution {
public:
    void dfs(TreeNode* root,string& s, vector<string>& v){
        if(!root){
            return;
        }
        int n = s.size();
        if(!s.empty()){
            s+="->";
        }
        s+=to_string(root->val);
        if(!root->left && !root->right){
            v.push_back(s);
        }
        else{
            dfs(root->left,s,v);
            dfs(root->right,s,v);
        }
        s.resize(n);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s;
        dfs(root,s,v);
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
