#include <iostream>
using namespace std;
/* Node is defined as*/
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
// time complexity O(n) and space complexity O(1)
class Solution {
  public:
    Node* segregate(Node* head) {
        // method 2 dutch natinal flag algo , take three separate linked list and then connect them at last
        // rerranging links
        Node* zeroshead = new Node(0),*oneshead = new Node(0),*twoshead = new Node(0),*zerostail = zeroshead,*onestail = oneshead,*twostail = twoshead;
        
        
        Node* temp = head;
        while(temp){
            if(temp->data==0){
                zerostail->next = temp;
                zerostail = zerostail->next;
            }
            else if(temp->data==1){
                onestail->next = temp;
                onestail = onestail->next;
            }
            else{
                twostail->next = temp;
                twostail = twostail->next;
            }
            temp = temp->next;
        }
        //at last merge them
        zerostail->next = (oneshead->next)?oneshead->next:twoshead->next;
        onestail->next = twoshead->next;
        twostail->next = nullptr;
        
        //New head is start
        head = zeroshead->next?zeroshead->next:oneshead->next?oneshead->next:twoshead->next;
        
        //delete the dummy nodes
        delete zeroshead;
        delete oneshead;
        delete twoshead;
        
        return head;
    }
};

int main() {
    // Create linked list: 1->2->0->1->2->0->1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(1);

    Solution sol;
    Node* sortedHead = sol.segregate(head);

    // Print the sorted linked list
    Node* temp = sortedHead;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Free memory
    temp = sortedHead;
    while (temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}