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
    void totalCols(Node* root, int& maxi ,int& mini, int col){
        if(!root) return;
        maxi = max(maxi,col);
        mini = min(mini,col);
        totalCols(root->left,maxi,mini,col-1);
        totalCols(root->right,maxi,mini,col+1);
    }
    void dfs(Node*root,int offset,int col,int row,vector<pair<int,int>>& v){
        if(!root) return;
        if(v[col+offset].first<row){
            v[col+offset] = {row,root->data};
        }
        // we are changing the order here so that we can get the value of rightmost first when both are in the same col and same row
        // it is mentioned in the question multiple bottom=most nodes for a hd from the root, the the later one in the level order is considered.
        dfs(root->right,offset,col+1,row+1,v);
        dfs(root->left,offset,col-1,row+1,v);
    }
    vector<int> bottomView(Node *root) {
        // do the same as topView just the opposite 
        // method 1 ; dfs 
        // step 1 : get the width , means no of cols
        int maxi = 0,mini = 0;
        totalCols(root,maxi,mini,0);
        int totalCol = maxi-mini+1;
        int offset = -mini;
        vector<pair<int,int>> v(totalCol,make_pair(INT_MIN,-1));
        dfs(root,offset,0,0,v);
        vector<int> res;
        for(auto& p:v){
            res.push_back(p.second);
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
