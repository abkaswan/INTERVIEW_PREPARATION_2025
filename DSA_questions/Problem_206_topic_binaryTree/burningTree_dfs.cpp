#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
Time and Space Complexity Analysis:

1. findParents():
   - Traverses the entire tree to record parent pointers for each node.
   - Time Complexity: O(N), where N = number of nodes.
   - Space Complexity: O(N) for parent map + O(H) recursion stack (H = height of tree).

2. findNode():
   - DFS to locate the target node in the tree.
   - Time Complexity: O(N) in worst case.
   - Space Complexity: O(H) for recursion stack.

3. findTime():
   - DFS traversal from target node, moving to left, right, and parent nodes.
   - Each node is visited exactly once using the 'visited' set.
   - Time Complexity: O(N)
   - Space Complexity: O(N) for visited set + O(H) recursion stack.

4. minTime():
   - Calls findParents() → O(N)
   - Calls findNode() → O(N)
   - Calls findTime() → O(N)
   - Overall Time Complexity: O(N)
   - Overall Space Complexity: O(N) (parent map + visited set + recursion stack)

Notes:
- Worst-case recursion stack = height of tree (H), up to N for skewed tree.
- This approach ensures each node is visited at most once.
*/


class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void findTime(Node* node,unordered_map<Node*,Node*>& parent,int& maxTime, int currTime,unordered_set<Node*>& visited){
        // if(!node || visited.count(node)){
        //     maxTime = max(currTime,maxTime);
        //     return;
        // }
        if(!node) { maxTime = max(maxTime, currTime-1); return; }
        if(visited.count(node)) return;

        
        visited.insert(node);
        // to left
        findTime(node->left,parent,maxTime,currTime+1,visited);
        // to right
        findTime(node->right,parent,maxTime,currTime+1,visited);
        // to parent
        if(parent[node])
            findTime(parent[node],parent,maxTime,currTime+1,visited);
        
    }
    void findParents(Node* root, unordered_map<Node*,Node*>& parent){
        if(!root) return;
        if(root->left){
            parent[root->left] = root;
            findParents(root->left,parent);
        }
        if(root->right){
            parent[root->right] = root;
            findParents(root->right,parent);
        }
    }
    Node* findNode(Node* root,int target){
        if(!root) return nullptr;
        if(root->data == target) return root;
        Node* left = findNode(root->left, target);
        return left ? left : findNode(root->right, target);
    }
    int minTime(Node* root, int target) {
        // method 1 : dfs 
        // find the parent list first 
        unordered_map<Node*,Node*> parent;
        // dfs traversal for parent
        findParents(root,parent);
        // Need to find the Node* also for the target
        Node* targeto;
        targeto = findNode(root,target);
        // next step is to do the traversal and get the time
        int maxTime = 0;
        unordered_set<Node*> visited;
        findTime(targeto,parent,maxTime,0,visited);
        return maxTime;
    }
};
int main() {
    // Example usage:
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    int target = 2;
    int timeToBurn = sol.minTime(root, target);
    cout << "Time to burn the tree starting from node " << target << ": " << timeToBurn << endl;

    return 0;
}