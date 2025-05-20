/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        ListNode* nxt = head;
        if(head == nullptr) return head;
        ListNode* evenTemp = head->next;

        while(temp->next!=nullptr && temp->next->next!=nullptr){
            nxt = temp->next;
            temp->next = nxt->next;
            nxt->next = temp->next->next;
            temp = temp->next;
        }
        if(evenTemp!=nullptr)
            temp->next = evenTemp;
        return head;
    }
};
int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = s.oddEvenList(head);
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}
