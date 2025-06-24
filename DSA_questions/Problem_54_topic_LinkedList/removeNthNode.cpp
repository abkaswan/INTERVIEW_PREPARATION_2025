#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Time Complexity: O(L) where L is the length of the linked list
// Space Complexity: O(1) since we are not using any extra space except for a few pointers
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ok simple solution move forward first pointer n places and then start moving the last element after that , when the first pointer reaches the end , then delete the second pointer and adjust the list before that 

        ListNode* prev=nullptr,*curr=head,*nxt=head;
        while(n--){
            nxt = nxt->next;
        }
        while(nxt!=nullptr){
            prev = curr;
            curr=curr->next;
            nxt = nxt->next;
        }
        if(!prev) //this means we are about to delete the very first element
            head = head->next;
        else
            prev->next = curr->next;
        delete curr;
        return head;
    }
};
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int n = 2; // Remove the 2nd node from the end
    head = solution.removeNthFromEnd(head, n);

    // Print the resulting linked list
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Free the allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

