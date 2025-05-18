#include <iostream>
#include <vector>
using namespace std;
//O(N) time complexity and O(n) space complexity
// Structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function for traversing tree using
// preorder postorder and inorder method
void PostPreInOrderInOneFlowRecursive(Node* root,
                                      vector<int>& pre,
                                      vector<int>& post,
                                      vector<int>& in)
{
    if(root == nullptr) return;
    pre.push_back(root->data);
    PostPreInOrderInOneFlowRecursive(root->left,pre,post,in);
    in.push_back(root->data);
    PostPreInOrderInOneFlowRecursive(root->right,pre,post,in);
    post.push_back(root->data);
    
}

// Driver Code
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->left->right
        = new Node(12);
    root->left->right->left = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);

    // Declaring the vector function to store
    // in, post, pre order values
    vector<int> pre, post, in;

    // Calling the function;
    PostPreInOrderInOneFlowRecursive(
        root, pre, post, in);

    // Print the values of Pre order, Post order
    // and In order
    cout << "Pre Order : ";
    for (auto i : pre) {
        cout << i << " ";
    }

    cout << endl;
    cout << "Post Order : ";
    for (auto i : post) {
        cout << i << " ";
    }
    cout << endl;
    cout << "In Order : ";
    for (auto i : in) {
        cout << i << " ";
    }
    return 0;
}