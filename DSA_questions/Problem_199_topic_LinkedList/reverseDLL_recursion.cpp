#include <iostream>
using namespace std;
// time complexity : O(n) and space complexity : O(n)
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
  public:
    Node *reverse(Node *head) {
        // method 2 : use recursion ?
        if(!head) return head;
        if(!head->next){
            // this is the new head after reversal return it
            head->prev = nullptr;
            return head;
        }
        // we keep this newHead fixed and return it because this is original head
        Node* newHead = reverse(head->next);
        
        // reverse the list like this 
        head->next->next = head;
        head->prev = head->next;
        head->next = nullptr;
        
        return newHead;
    }
};
int main() {
    Solution sol;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    Node *newHead = sol.reverse(head);
    while(newHead){
        cout << newHead->data << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}
