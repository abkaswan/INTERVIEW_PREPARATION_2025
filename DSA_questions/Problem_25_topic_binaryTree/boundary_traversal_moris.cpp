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
    // earlier we were traversing it recursively now we will do iterative 
    // morris traversal : o(n) tc and O(1) sc
    bool isLeaf(Node* root){
        return !root->left && !root->right;
    }
    void lbt(Node* root, vector<int>&v){
        if(!root) return;
        Node* curr = root;
        while(!isLeaf(curr)){
            v.push_back(curr->data);
            if(curr->left) curr=curr->left;
            else curr = curr->right;
        }
    }
    // using morris traversal to find the leaf nodes.
    void lf(Node* root, vector<int>&v){
        Node* curr = root;
        while(curr){
            // doing simple inorder first : left, root , right ,,,, and after that whereever we are adding values just comment those out and only find how we can get leaf nodes
            // we will go to left node if there is any
            if(!curr->left){
                // if current is a leaf node 
                if(!curr->right)
                    v.push_back(curr->data);
                //because in inorder if we have [left,root,right] and we have reached left,root already we need to go to right no ? 
                curr = curr->right;
            }
            else{
                //now we will find the rightmost node in left subtree -- predecessor in inorder traversal before going to left 
                // if we want to return back we need some threads that's why it is also called threded traversal or something
                Node* prev = curr->left;
                while(prev->right!=nullptr && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right!=curr){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    // if prev is a leaf node
                    if(!prev->left)
                        v.push_back(prev->data); 
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
    }
    void rrbt(Node* root, vector<int>&v){
        if(!root) return;
        vector<int> temp;
        Node * curr = root;
        while(!isLeaf(curr)){
            temp.push_back(curr->data);
            
            if(curr->right) curr=curr->right;
            else curr = curr->left;
        }
        for(int i = temp.size()-1;i>=0;i--){
            v.push_back(temp[i]);
        }
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> v;
        if(!root) return {};
        if(!isLeaf(root)) //add root data if it's not leaf , because if it is that will be taken care by lf function 
            v.push_back(root->data);
        //lbt : left boundary traversal
        lbt(root->left,v);
        //lf : leaf nodes , using moris traversal here for inorder
        lf(root,v);
        //rrbt : reverse right boundary traversal
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
