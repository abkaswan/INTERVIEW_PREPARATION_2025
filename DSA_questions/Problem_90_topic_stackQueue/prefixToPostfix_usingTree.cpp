#include <iostream>
#include <stack>
#include <string>
using namespace std;
// time complexity : O(n) for buildTreeFromPrefix and O(n) for postOrder traversal
// space complexity : O(n) for the stack used in buildTreeFromPrefix and O(h) for the recursion stack in postOrder, where h is the height of the tree
struct Node {
    char data;
    Node *left, *right;
    Node(char c) : data(c), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/';
}

Node* buildTreeFromPrefix(const string& prefix) {
    stack<Node*> st;
    for (int i = prefix.size() - 1; i >= 0; --i) {
        char c = prefix[i];
        Node* node = new Node(c);
        if (isOperator(c)) {
            node->left = st.top(); st.pop();
            node->right = st.top(); st.pop();
        }
        st.push(node);
    }
    return st.top();
}

void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}

int main() {
    string prefix = "*+ab-cd";
    Node* root = buildTreeFromPrefix(prefix);
    postOrder(root);
    // outputs: ab+cd-*
    return 0;
}
