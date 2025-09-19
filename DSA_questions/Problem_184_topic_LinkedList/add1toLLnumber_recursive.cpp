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
    // using recursion 
    int addCarry(Node* head){
        if(head==nullptr) return 1;
        int res = head->data+addCarry(head->next);
        
        head->data = res%10;
        return res/10;
    }
    Node* addOne(Node* head) {
        int carry = addCarry(head);
        // if we reach at the end and all were 9s need to add new Node to carry 1
        if(carry!=0){
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
