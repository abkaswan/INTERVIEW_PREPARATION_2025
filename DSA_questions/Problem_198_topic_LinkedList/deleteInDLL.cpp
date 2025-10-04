#include <iostream>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // noted : positoins are 1-indexed and remove it for positoin x
        // no need to assign temp->next and temp->prev to nullptr also : that’s fine but not really required. It’s enough to adjust neighbors and delete temp.
        Node* temp = head;
        while(x>1){
            temp = temp->next;
            x--;
        }
        // if it is head 
        if(!temp->prev){
            head = temp->next;
            if(head) head->prev = nullptr;
            // temp->next = nullptr;
        }
        // if it is end
        else if(!temp->next){
            temp->prev->next = nullptr;
            // temp->prev = nullptr;
        }
        // if it is normal in the middle at some position 
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            // temp->prev = nullptr;
            // temp->next = nullptr;
        }
        delete temp; // free memory
        return head;
    }
};
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->prev = head;
    head->next->next->prev = head->next;

    Solution sol;
    head = sol.delPos(head, 2);
    Node* temp = head;
    while(temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    return 0;
}