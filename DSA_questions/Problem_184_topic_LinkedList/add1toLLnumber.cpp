#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    Node* reverseIt(Node* head){
        Node* prev = nullptr,*curr = head,*nxt = head;
        while(nxt){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // return head of list after adding one
        // reverse the linked list
        head = reverseIt(head);
        
        Node* temp = head;
        while(temp){
            if(temp->data==9){
                temp->data = 0;
            }
            else{
                temp->data += 1;
                break;
            }
            temp = temp->next;
        }
        
        //reverse again
        head = reverseIt(head);
        // if we reach at the end and all were 9s need to add new Node to carry 1
        if(!temp){
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        
        return head;
    }
};
int main() {
    // Create linked list: 4->5->9
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(9);

    Solution sol;
    Node* ansList = sol.addOne(head);

    // Print the resultant linked list
    Node* temp = ansList;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Free memory
    temp = ansList;
    while (temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}