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
    bool isPalindrome(ListNode* head) {
        // we can just reverse the linked list in another ll and compare and say yes it is palindrom , or take one stack , then comprae the values
        // m1 ; take a stack fill that and compare , tc : O(n) , sc : O(n)
        stack<int> s;
        ListNode* temp = head;
        while(temp!=nullptr){
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(!s.empty()){
            int x = s.top();
            s.pop();
            if(x!=temp->val) return false;
            temp = temp->next;
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
