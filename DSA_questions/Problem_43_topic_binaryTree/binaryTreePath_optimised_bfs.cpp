#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct Entry{
        TreeNode* node; // the current tree node
        Entry* parent; // pointer to the parent entry
};
// TC : O(N+M*h) == skwered tree : O(N)(M==1) , balanced tree : O(NlogN)
// visting nodes : O(N) 
// leaf post-processing (explained below) : O(Mh)

// SC : O(N+M*h)/O(W+N)
// queue of entries : one pointer and one parent so O(W) entries
// parent links : total O(N) nodes allocated (if you don't free)
// post-processsing O(M*h)
class Solution {  
public:
    // defer string-concatenate until the very end
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        queue<Entry*> q;
        q.push(new Entry{root,nullptr});
        vector<Entry*> leaves;
        while(!q.empty()){
            Entry* e = q.front();
            q.pop();

            if(!e->node->left && !e->node->right){
                leaves.push_back(e); //collect leaf entries
            }
            if(e->node->left) q.push(new Entry{e->node->left,e});
            if(e->node->right) q.push(new Entry{e->node->right,e});
        }
        // we were collecting parent node so that we can use it to get the paths 
        // tc for this:
        // walk up the parent chain : O(h)
        // reverse vector : O(h)
        // build the string via ostringstream : do one << per "->" and per value , so 2h streams writes  : O(h)
        // total per leaf : O(h)+O(h)+O(h) = O(h)
        // so total : O(M*h)

        // sc for this : 
        // per leaf vpath : O(h) 
        // per leafostringstream's internal buffer : O(h) chars
        // per leaf a small constant stack / frame overhead 
        // O(M*h) for all leaves
        for(auto leaf: leaves){
            vector<int> vpath;
            Entry* curr = leaf;
            while(curr){
                vpath.push_back(curr->node->val);
                curr = curr->parent;
            }
            //reverse it 
            reverse(vpath.begin(),vpath.end());
            // build the string with "->" separators
            ostringstream oss; //std c++ stream that writers formatted data into an internal string buffer.
            for(int i = 0;i<vpath.size();i++)
            {
                if(i) oss<<"->";
                oss<<vpath[i];
            }
            v.push_back(oss.str());
        }
        return v;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    vector<string> v = s.binaryTreePaths(root);
    for(auto& i:v){
        cout<<i<<endl;
    }
    return 0;
}

