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
    void totalCols(Node* root, int& maxi , int& mini , int col){
        if(!root) return;
        maxi=max(maxi,col);
        mini = min(mini,col);
        totalCols(root->left,maxi,mini,col-1);
        totalCols(root->right,maxi,mini,col+1);
    }
    void dfs(Node* root, vector<pair<int,int>>& v,int offset,int row,int col){
        if(!root) return;
        if(v[offset+col].first>row) v[offset+col] = {row,root->data};
        dfs(root->left,v,offset,row+1,col-1);
        dfs(root->right,v,offset,row+1,col+1);
    }
    vector<int> topView(Node *root) {
        // enter the first entry of each column , no need to count the rows also right ?
        // just check if in the vector there is already something if there is no entry , otherwise enter
        
        // step1: first get the total columns that are there
        int maxi = 0,mini = 0,offset;
        totalCols(root,maxi,mini,0);
        int totalCol = maxi-mini+1;
        offset = -mini; // so that we can store it in the vector
        // step2 : start to initialize the vector with the totalColumn size
        vector<pair<int,int>> v(totalCol,make_pair(INT_MAX,-1));
        // step3: now do the dfs 
        dfs(root,v,offset,0,0);
        vector<int> res;
        for(const auto& p:v){
            res.push_back(p.second);
        }
        return res;
        
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
