#include <iostream>
#include <vector>
using namespace std;
// Time complexity : , space complexity : 
struct Node {
    int data;
    struct Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void allTraversal(Node* root)
{
    vector<int> pre;
    vector<int> post;
    vector<int> in;
    // take a stack where we will be putting a pair like first , second values , 
    // first will be the root node, second will be the state that will define where we need to push the results.
    stack<pair<Node*, int>> s;
    // here the simple idea is this > 
    // preorder , if there is anything on the left we push to the stack, the right part of this the inorder will take care
    // inorder , if there is anything on the right we push to the stack, the other parts like left and right we are incrementing the state during preorder that will take care
    // postorder , for this all the parts will be taken care, we are incrementing the state during inorder that will take care

    //push the root first with state 1
    s.push({root, 1});
    if(root==nullptr)return;
    while(!s.empty())
    {
        Node* curr = s.top().first;
        int state = s.top().second;
        s.pop();
        if(state == 1){
            pre.push_back(curr->data);
            s.push({curr,++state});
            if(curr->left!=nullptr){
                s.push({curr->left, 1});
            }
        }
        else if(state == 2)
        {
            in.push_back(curr->data);
            s.push({curr,++state});
            if(curr->right!=nullptr){
                s.push({curr->right,1});
            }
        }
        else{
            post.push_back(curr->data);
        }
    }

    cout << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++) {
        cout << pre[i] << " ";
    }
    cout << "\n";
    cout << "Inorder Traversal: ";
    for (int i = 0; i < in.size(); i++) {
        cout << in[i] << " ";
    }
    cout << "\n";
    cout << "Postorder Traversal: ";
    for (int i = 0; i < post.size(); i++) {
        cout << post[i] << " ";
    }
    cout << "\n";
}

int main()
{

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    allTraversal(root);

    return 0;
}