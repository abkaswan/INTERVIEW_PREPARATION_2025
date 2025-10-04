#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// Time Complexity: O(N)
//   - Each node is visited at most twice: once in dfs to find target, once in dfsDown.
//   - Therefore total work is proportional to number of nodes.
//
// Space Complexity: O(H)
//   - Recursion stack goes up to the height H of the tree.
//   - No extra data structures apart from integer variables.
//   - Worst case (skewed tree): O(N), Best case (balanced tree): O(log N)

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
    void dfsDown(Node* node, int dist, int& maxTime) {
        if (!node) return;
        maxTime = max(maxTime, dist);
        dfsDown(node->left, dist+1, maxTime);
        dfsDown(node->right, dist+1, maxTime);
    }

    int dfs(Node* node, int target, int& maxTime) {
        if (!node) return -1;
        if (node->data == target) {
            dfsDown(node, 0, maxTime);
            return 0;                    // distance to target is 0
        }

        int L = dfs(node->left, target, maxTime);
        if (L != -1) {
            maxTime = max(maxTime, L + 1);        // <-- update for this ancestor node
            dfsDown(node->right, L + 2, maxTime);
            return L + 1;
        }

        int R = dfs(node->right, target, maxTime);
        if (R != -1) {
            maxTime = max(maxTime, R + 1);        // <-- update for this ancestor node
            dfsDown(node->left, R + 2, maxTime);
            return R + 1;
        }

        return -1;
    }

    int minTime(Node* root, int target) {
        int maxTime = 0;
        dfs(root, target, maxTime);
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