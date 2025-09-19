#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// time complexity : O(max(m,n)) where m and n are lengths of two linked lists
// space complexity : O(max(m,n)) for the new linked list

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head makes code cleaner (avoids checking for null repeatedly)
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next;  // skip dummy node
    }
};

int main() {
    // Create linked list: 4->5->9 , this is reverse thoguh right so actual number is 954
    ListNode* head1 = new ListNode(4);
    head1->next = new ListNode(5);
    head1->next->next = new ListNode(9);

    // another number is 2->3->1 which is in reality 132
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(1);

    Solution sol;
    ListNode* ansList = sol.addTwoNumbers(head1,head2);

    // Print the resultant list : it is 1086
    ListNode* temp = ansList;
    while (temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Free memory
    temp = ansList;
    while (temp) {
        ListNode* next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}