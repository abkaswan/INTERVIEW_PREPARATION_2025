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
        // method 1 count all 0s 1s and 2s and replace them 
        int count[3] = {0,0,0};
        Node* temp = head;
        while(temp){
            count[temp->data]++;
            temp = temp->next;
        }
        // replace them in the original LL
        temp = head;
        for(int i = 0;i<3;i++){
            while(count[i]--){
                temp->data = i;
                temp=temp->next;
            }
        }
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