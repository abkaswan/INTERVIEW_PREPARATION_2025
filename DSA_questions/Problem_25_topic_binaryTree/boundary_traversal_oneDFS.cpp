/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
#include <iostream>
#include <vector>
using namespace std;
// Structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution {
  public:
    // using dfs : but only one traversal 
    // lb : is left boundary and rb : is right boundary
    // tc : O(n) and sc : O(n)
    void dfs(Node* root,bool lb , bool rb, vector<int>&v,bool isFirstTime){
        if(!root) return;
        // for left boundary we are adding 
        // using FirstTime we will be adding root node at the beginning always
        if(lb || isFirstTime) v.push_back(root->data);
        // for leaf nodes we are adding
        else if(!root->left && !root->right) v.push_back(root->data);
        dfs(root->left,lb,rb && !root->right,v,false);
        dfs(root->right,lb && !root->left,rb,v,false);
        // for right boundary we are adding but in reverse order ,
        // extra lb is so that we don't add root node and the other is so that we don't count leaf nodes twice
        if(rb && !isFirstTime && (root->left || root->right)) v.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        if(!root) return {};
        vector<int> v;
        bool leftB = !root->left?false:true;
        bool rightB = !root->right?false:true;
        // isFirstTime tells us if we called this function dfs for the first time and if yes then add the root in the beginnning only 
        dfs(root,leftB,rightB,v,true);
        return v;
        
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> v = Solution().boundaryTraversal(root);
    for (int i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
