#include <iostream>
#include <queue>
using namespace std;

// O(n):  you store up to n elements in q1 and q2 not more thant that so O(n)
class MyStack {
private : 
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    // tc : O(n)
    void push(int x) {
        // always enter in q2 
        q2.push(x);
        //move all elements from q2 to q1
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
        // so now q1 is like the ultimate q2
    }
    // tc : O(1)
    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }
    // tc : O(1)
    int top() {
        return q1.front();
    }
    // tc : O(1)
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main() {
    MyStack* obj = new MyStack();
    obj->push(10);
    obj->push(20);
    int param_2 = obj->pop();
    std::cout << "Popped: " << param_2 << std::endl;
    int param_3 = obj->top();
    std::cout << "Top element: " << param_3 << std::endl;
    bool param_4 = obj->empty();
    std::cout << "Is stack empty? " << (param_4 ? "Yes" : "No") << std::endl;

    delete obj; // Clean up
    return 0;
}

