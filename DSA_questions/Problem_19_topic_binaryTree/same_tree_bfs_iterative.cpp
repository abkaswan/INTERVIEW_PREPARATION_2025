#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.emplace(p, q);
        while(!qu.empty()){
            auto [x,y]=qu.front();
            qu.pop();
            if(x==nullptr || y==nullptr){
                if(x!=y)return false;
                continue;
            }
            if(x->val!=y->val) return false;
            qu.emplace(x->left,y->left);
            qu.emplace(x->right,y->right);    
        }
        return true;
    }
};
int main() {
    // Example usage
    Solution solution;
    
    // Create two trees
    TreeNode* tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    // Check if they are the same
    bool result = solution.isSameTree(tree1, tree2);
    std::cout << (result ? "Trees are the same" : "Trees are not the same") << std::endl;

    // Clean up
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}

