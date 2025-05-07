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
        bool hasCycle(ListNode *head) {
            // one solution i am thinking  :
            // use slow and fast pointers -- floyd's cycle-finding algo // 2 pointers or slow-fast pointers approach \
            // imagine this scenario ias if two people are running at x and 2x speed --TC : O(n) and SC : O(1)
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast!=NULL && fast->next!=NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
                if(fast == slow) return true;
            }
            return false;
        }
};

int main() {
    // Creating nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);

    // Introducing a cycle: pointing the next of the last node to the second node
    head->next->next->next = head->next;

    Solution sol;
    if (sol.hasCycle(head))
        cout << "Cycle detected in the linked list." << endl;
    else
        cout << "No cycle detected in the linked list." << endl;

    // Note: In a real-world scenario, we should free the allocated memory.
    // However, since there's a cycle, deleting nodes would require additional handling to avoid infinite loops.

    return 0;
}