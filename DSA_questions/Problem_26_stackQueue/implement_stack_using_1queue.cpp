#include <iostream>
#include <queue>
using namespace std;

// O(n):  one queue you are using so
class MyStack {
private : 
    queue<int> q;
public:
    MyStack() {
        
    }
    // tc : O(n)
    void push(int x) {
        // here we will just need to rotate the queue after pushing the element
        q.push(x);
        int n = q.size();
        for(int i = n-1;i>0;i--){
            q.push(q.front());
            q.pop();
        }
    }
    // tc : O(1)
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    // tc : O(1)
    int top() {
        return q.front();
    }
    // tc : O(1)
    bool empty() {
        return q.empty();
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

