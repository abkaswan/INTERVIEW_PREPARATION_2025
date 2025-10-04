#include <iostream>
using namespace std;
// time complexity: O(n) and space complexity: O(h) worst case O(n)


// need to check below things : 
// 1. all leaf nodes are on same level --> need to check height of left and right subtree --> we have a function getHeight for this
// 2. all non-leaf nodes have both children --> need to check if any node has one child missing --> need recursion for this
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    int getHeight(Node* root){
        int height = 0;
        while(root){
            root = root->left;
            height+=1;
        }
        return height;
    }
    bool isPerfect(Node *root) {
        // so for this to happen we need to compare the height of left subtree and right subtree if it is same then whooo we have "Yes"
        if(!root) return true;
        // if one child is missing not pefect
        if(!root->left && !root->right) return true;
        if(!root->left || !root->right) return false;
        
        // checking if all the leaf nodes on same height + checking if all non-leaf nodes has both children
        return getHeight(root->left)==getHeight(root->right) && isPerfect(root->left) && isPerfect(root->right);
        
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    if (sol.isPerfect(root)) {
        cout << "The binary tree is perfect." << endl;
    } else {
        cout << "The binary tree is not perfect." << endl;
    }

    return 0;
}