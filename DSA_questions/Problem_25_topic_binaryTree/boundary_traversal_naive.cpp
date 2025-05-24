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
    //lbt : left boundary tree , left boundary except for leaf nodes
    void lbt(Node* root,vector<int>& v){
        if(!root || (!root->left && !root->right)) return;
        
        v.push_back(root->data);
        if(root->left)
            lbt(root->left,v);
        else
            lbt(root->right,v);
    }
    //leaf nodes : in left to right order
    void lf(Node* root,vector<int>& v){
        if(!root) return;
        if(root->left==nullptr && root->right==nullptr)
        {    
            v.push_back(root->data);
            return;
        }
        lf(root->left,v);
        lf(root->right,v);
    }
    //rrbt : reverse right boundary tree, right boundary nodes in reverse order except for leaf node and the very first root node
    void rrbt(Node* root,vector<int>& v)
    {
        if(!root || (!root->left && !root->right)) return;
        if(root->right)
            rrbt(root->right,v);
        else
            rrbt(root->left,v);
        v.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        if(!root) return {};
        if(!root->left && !root->right) return {root->data};
        vector<int> v;
        v.push_back(root->data);
        // do three traversals as mentioned in the problem description
        //here sending root->left because root has already been included in beginning
        lbt(root->left,v);
        lf(root,v);
        //here sending root->right because root has already been included in beginning
        rrbt(root->right,v);
        
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
