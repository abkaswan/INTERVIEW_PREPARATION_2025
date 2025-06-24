#include <iostream>

using namespace std;
// time complexity O(n) and space complexity O(1)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // odd element : we need to go to middle 
        // even element : we need to go to middle+1 according to the question
        // can do it by below code in O(n)tc and O(1)sc

        if(!head->next) return nullptr;
        ListNode* curr=head, *nxt=head,*prev=nullptr;
        while(nxt && nxt->next){
            prev = curr;
            curr = curr->next;
            nxt = nxt->next->next;
        }
        prev->next = curr->next;
        delete curr;
        return head;

    }
};
int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head = s.deleteMiddle(head);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
