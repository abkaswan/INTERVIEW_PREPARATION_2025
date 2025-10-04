#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity: O(N log k)
//   - N = total number of nodes across all lists
//   - Each node is pushed and popped from the heap once
//   - Heap size is at most k (number of lists), so each operation costs O(log k)
//   - Total = O(N log k)
//
// Space Complexity: O(k)
//   - Heap holds at most one node from each list at a time
//   - We do not create new nodes, only rearrange pointers
//   - Extra space = O(k)


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Custom comparator for min heap
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  
        // '>' means smaller value gets higher priority (min-heap)
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // use heap for this
        // step 1 : use Min heap -> smallest element at the top
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // step 2 : enter only the first elements from each of the list(which are smallest elements in that particular list because sorted in ascending order)
        for(auto x : lists){
            if(x) minHeap.push(x);
        }
        if(minHeap.empty()) return NULL;

        // step 3 : pop the min element each time , add it to the new node , add next element of the popped element in the minHeap now
        ListNode* root = minHeap.top();
        minHeap.pop();
        if(root->next) minHeap.push(root->next);
        ListNode* temp = root;
        while(!minHeap.empty()){
            temp->next = minHeap.top();
            minHeap.pop();
            temp = temp->next;
            if(temp->next) minHeap.push(temp->next); // add next element of the popped element in the minHeap
        }

        return root;

    }
};
int main() {
    Solution s;
    vector<ListNode*> lists;
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(4);
    ListNode* l3 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;

    ListNode* l4 = new ListNode(1);
    ListNode* l5 = new ListNode(3);
    ListNode* l6 = new ListNode(4);
    l4->next = l5;
    l5->next = l6;

    ListNode* l7 = new ListNode(2);
    ListNode* l8 = new ListNode(6);
    l7->next = l8;

    lists.push_back(l1);
    lists.push_back(l4);
    lists.push_back(l7);

    ListNode* root = s.mergeKLists(lists);

    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;

    return 0;
}
