#include <iostream>
#include <stack>
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
    // bool isPalindrome(ListNode* head) {
    //     // m1 ; take a stack fill that and compare , tc : O(n) , sc : O(n)
    //     // m2 : take the middle point , reverse the ll from that point , reserve the middle point, compare 
    //     ListNode* slow = head, *fast = head;
    //     while(fast!=nullptr && fast->next!=nullptr){
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     // now slow points to middle node so try to reverse it from here , the second half
    //     ListNode* prev = nullptr,*curr = slow,*nxt = slow;
    //     while(curr!=nullptr){
    //         nxt = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = nxt;
    //     }
    //     // so now prev is the starting point for this ?
    //     while(prev!=nullptr && head!=nullptr){
    //         if(prev->val!=head->val) return false;
    //         prev = prev->next;
    //         head = head->next;
    //     }
    //     return true;
    // }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) 
            return true;
        // m1 ; take a stack fill that and compare , tc : O(n) , sc : O(n)
        // m2 : take the middle point , reverse the ll from that point , reserve the middle point, compare 
        ListNode* slow = head, *fast = head,*prev = nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next; // because if we write it after that , the link is already severed as we are trying to reverse the ll so need to do it here
            // during finding the middle node we go through the first half , reverse it on the fly also
            ListNode* nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;            
        }
        // so now slow is the starting point for the second half, if odd length ex : 1 2 3 2 1 then it slow will point to 3 so we need to skip it
        if(fast) slow = slow->next;
        // now we know the prev will point to the start of the first half ll and slow will point to the start of the second half of ll
        while(prev!=nullptr){
            if(prev->val!=slow->val) return false;
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    cout<<(s.isPalindrome(head) ? "Yes" : "No")<<endl;
    return 0;
}
