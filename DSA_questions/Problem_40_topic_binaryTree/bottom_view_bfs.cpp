// Function to return a list containing the bottom view of the given tree.
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // do the same as topView just the opposite 
        // method 2 ; bfs level order traversal using queue
        int maxi = 0,mini = 0;
        
        queue<pair<Node*,int>> q;
        unordered_map<int,int> v;
        q.push({root,0});
        while(!q.empty()){
            auto p = q.front();
            int col = p.second;
            Node* root = p.first;
            q.pop();
            //just keep overriding as we will need the last element
            v[col]=root->data;
            
            mini = min(mini,col);
            maxi = max(maxi,col);
            // we will do root->right first and then left to give the latter one preference
            if(root->left) q.push({root->left,col-1});
            if(root->right) q.push({root->right,col+1});
        }
        vector<int> res;
        for(int i = mini;i<=maxi;i++)
        {
            res.push_back(v[i]);
        }
        return res;
        
    }
};

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    Solution ob;
    vector<int> res = ob.bottomView(root);

    for (int i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}
