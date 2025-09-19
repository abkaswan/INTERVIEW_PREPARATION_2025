#include <iostream>
using namespace std;
// Definition for singly-linked list.

// time complexity O(max(m,n)) space O(1)
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {    
        //reverse both the list first -- no need already reversed
        // check which one is longer so that you could save the data there ?
        ListNode* temp1 = l1,*temp2 = l2,*longer,*finalRes;
        int largee=0;
        while(temp1 && temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1){
            // temp1 is longer, save there , so save that temp1 is longer
            largee = 0;
        }
        else{
            // temp2 is longer , save there
            largee = 1;
        }
        // add numbers now with least significant bit in front
        // reset temp1 and temp2 again
        temp1 = l1,temp2 = l2;
        longer = largee?temp2:temp1;
        finalRes = largee?temp2:temp1;

        ListNode* prev;

        int carry = 0;
        while(temp1 && temp2){
            int res = temp1->val+temp2->val+carry;
            if(res>=10){
                longer->val = res%10;
                carry = 1;
            }
            else{
                longer->val = res;
                carry = 0;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
            prev = longer;
            longer = longer->next;
            
        }
        // if longer is still not finished and we carry 1 - we can break as soon as carry is finished
        while(longer && carry == 1){
            int res = longer->val+carry;
            if(res>=10){
                longer->val = res%10;
                carry = 1;
            }
            else{
                longer->val = res;
                carry = 0;
                break;
            }
            prev = longer;
            longer = longer->next;
        }

        // if carry one is there but both list ended
        if(carry == 1){
            ListNode* newNode = new ListNode(1);
            prev->next = newNode;
        }
        // reverse it again -- already reversed so no need
        // return the head of list 1
        return finalRes;
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