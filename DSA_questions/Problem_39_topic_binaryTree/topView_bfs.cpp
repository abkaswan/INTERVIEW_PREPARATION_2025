#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // method 2 : bfs level order traversal using queue
        queue<pair<Node*,int>> q;
        q.push({root,0});
        unordered_map<int,int> firstSeen;
        // for each col maxi and mini is leftmost and rightmost indices 
        int mini = 0,maxi = 0;
        vector<int>v;
        
        while(!q.empty()){
            auto p = q.front();
            Node* root =p.first;int col = p.second;
            q.pop();
            if(firstSeen.find(col)==firstSeen.end())
                firstSeen[col]=root->data;
            mini = min(mini,col);
            maxi = max(maxi,col);
            
            if(root->left) q.push({root->left,col-1});
            if(root->right) q.push({root->right,col+1});
            
        }
        for(int i = mini;i<=maxi;i++){
            v.push_back(firstSeen[i]);
        }
        return v;
    }
};

int main() {
    Solution sol;
    Node *root = new Node{1};
    root->left = new Node{2};
    root->right = new Node{3};
    root->left->right = new Node{4};
    root->left->right->right = new Node{5};
    root->left->right->right->right = new Node{6};
    
    vector<int> res = sol.topView(root);
    for(int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
