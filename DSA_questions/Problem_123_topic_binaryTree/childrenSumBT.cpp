#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Time Complexity :
// We visit each node exactly once. At each node, we just do constant work (check values + recursive calls). ✅ O(n)

// Space Complexity :
// Recursion stack goes as deep as the height of the tree. Worst case (skewed tree, like a linked list) → O(n) Best/average case (balanced tree) → height = O(log n)
// ✅ So space = O(h), which is O(log n) for balanced, O(n) for skewed.

class Solution {
  public:
    int isSumProperty(Node *root) {
        if(!root) return 1; // empty tree valid
        if(!root->left && !root->right) return 1;
            
        int leftVal = root->left?root->left->data:0;
        int rightVal = root->right?root->right->data:0;
        
        if(root->data!=leftVal+rightVal) return 0;
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};
int main() {
    Solution sol;
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);
    int result = sol.isSumProperty(root);
    cout << (result ? "true" : "false") << endl; // Expected output: true
    return 0;
}