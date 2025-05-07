#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
    ListNode *detectCycle(ListNode *head) {
        //method 1 --> USE MAP , maybe unordered_map for this one. TC : O(n) and SC : O(n)
        unordered_map<ListNode*,int> mpp;
        while(head!=NULL)
        {
            if(mpp.find(head)!=mpp.end()) //means match is there
                return head;
            mpp.insert({head,1});
            head = head->next;
        }
        return NULL;
    }
};

int main() {
    // Creating nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    // loop would look like this.
    // 1---3---4
    //     |   |
    //      ---

    // Introducing a cycle: pointing the next of the last node to the second node
    head->next->next->next = head->next;

    Solution sol;
    if (sol.detectCycle(head)==NULL)
        cout << "no cycle" << endl;
    else
        cout << "Cycle detected in the linked list. The starting element is : "<< sol.detectCycle(head)->val << endl;

    // Note: In a real-world scenario, we should free the allocated memory.
    // However, since there's a cycle, deleting nodes would require additional handling to avoid infinite loops.

    return 0;
}