#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Time Complexity: O(N) 
//   -> Each node is visited at most twice (once for parent mapping, once for burning BFS).

// Space Complexity: O(N) 
//   -> Parent map O(N) + Visited set O(N) + Queues O(N).

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    int minTime(Node* root, int target) {
        // method 2 : bfs
        //step 1 : use bfs to find parents and find the target node
        unordered_map<Node*,Node*> parent;
        Node* targeto;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node->data == target){
                targeto = node;
            }
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        // step 2 : bfs traversal one more time to find the time
        int maxTime = 0;
        queue<Node*> q2;
        
        unordered_set<Node*>visited;
        q2.push(targeto);
        visited.insert(targeto);
        
        while(!q2.empty()){
            bool burned = false;
            int size = q2.size();
            // at each level wise we need to see  -- and increase the time like that 
            for(int i = 0;i<size;i++){
                Node* node = q2.front();
                q2.pop();
                if(node->left && !visited.count(node->left)){
                    visited.insert(node->left);
                    q2.push(node->left);
                    burned = true;
                }
                if(node->right && !visited.count(node->right)){
                    visited.insert(node->right);
                    q2.push(node->right);
                    burned = true;
                }
                if(parent.find(node) != parent.end() && !visited.count(parent[node])){
                    visited.insert(parent[node]);
                    q2.push(parent[node]);
                    burned = true;
                }
            }
            if(burned){
                maxTime+=1;
            }
        }
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
    
    cout << "Minimum time to burn the tree from target " << target << " is: " << timeToBurn << endl;
    
    // Clean up memory (delete nodes) if necessary
    return 0;
}