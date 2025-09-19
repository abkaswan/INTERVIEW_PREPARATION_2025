#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// time complexity: O(m+n) where m and n are the lengths of the two linked lists
// space complexity: O(1)

// NOTE : n a singly linked list, each node’s next points to only one node (or NULL).
// So if two lists ever intersect at a node (say c1), then from that point onward they share the entire tail (c1 → c2 → c3 → ...).
// There’s no way for them to “split apart again,” because c1->next is a single pointer, not two different branches.


// ultimate goal whichever list is smaller our goal is to make both of their head start from same position 
// either get length of list1 and list2 , whichever is long let it travel (list1>list2) list1-list2 otherise viceversa
// or we cna use this below method also , two pointer switching method
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA!=tempB){
            tempA = !tempA?headB:tempA->next;
            tempB = !tempB?headA:tempB->next;
        }
        return tempA;
    }
};
int main() {
    // Create two linked lists:
    // List A: 1 -> 2 \
    //                  3 -> 4 -> 5
    // List B:    6  /
    ListNode* common = new ListNode(3);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = common;

    ListNode* headB = new ListNode(6);
    headB->next = common;

    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);

    if (intersection) {
        std::cout << "Intersection at node with value: " << intersection->val << std::endl;
    } else {
        std::cout << "No intersection." << std::endl;
    }

    // Clean up memory (not strictly necessary for short test, but good practice)
    delete headA->next; // node 2
    delete headA;       // node 1
    delete headB;       // node 6
    delete common->next->next; // node 5
    delete common->next;       // node 4
    delete common;             // node 3

    return 0;
}