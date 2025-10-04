#include <iostream>
using namespace std;
// time complexity : O(n) and space complexity : O(1)
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
        // just return the head for this?
        Node* temp = head;
        Node* newHead = nullptr; // so that at last when temp is null we have the value right 
        
        while(temp){
            newHead = temp->prev;
            temp->prev = temp->next;
            temp->next = newHead;
            temp = temp->prev;
        }
        // because newHead is always one step back to the temp , now after the reversal for example : 1,2,6,7,3 here at the last iteration newHead will be 7 and temp will be null , all are reversed result is 3 7 6 2 1 and if we want the head it would be newHead->prev
        if(newHead){
            head = newHead->prev;
        }
        return head;
    }
};
int main()
{
    Solution sol;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(6);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(7);
    head->next->next->next->prev = head->next->next;

    Node *newHead = sol.reverse(head);
    while(newHead){
        cout << newHead->data << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}
