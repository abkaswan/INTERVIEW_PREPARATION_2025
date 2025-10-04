#include <iostream>
using namespace std;
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // note p<list.size() so no need to worry about it being at positon 0 also
        Node* newNode = new Node(x);
        Node* temp = head;
        
        while(p--){
            temp = temp->next;
        }
        // if we are adding at the end 
        if(!temp->next) {
            temp->next = newNode;
            newNode->prev = temp;
        }
        // apart from this we will be adding after the 0-th position only always so no need to think about the situation where we add at the head
        else{
            temp->next->prev = newNode;
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        return head;
    }
    
};
int main() {
    Solution sol;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    Node* newHead = sol.insertAtPos(head, 2, 10);
    Node* temp = newHead;
    while(temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    temp = newHead;
    while(temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    return 0;
}
