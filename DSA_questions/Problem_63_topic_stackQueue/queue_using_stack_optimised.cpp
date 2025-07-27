#include <iostream>
#include <stack>
using namespace std;

// Goal: Make push, pop, and peek amortized O(1) using two stacks. This means that while some individual operations (like pop or push) might take longer (say, O(n)), the average cost over many operations is still O(1).
// Push = O(1):
// Just push into s1.

// Pop = O(1) amortized:
// If s2 is empty:
// Move all elements from s1 to s2 (this takes O(n), but only happens occasionally)
// Then pop from s2.
// This shifting only happens once per element, so total work across n operations is O(n).

// | Operation      | Worst-case Time | Amortized Time | Space Complexity |
// | -------------- | --------------- | -------------- | ---------------- |
// | `push`         | O(1)            | O(1)           | —                |
// | `pop` / `peek` | O(n)            | O(1)           | —                |
// | `empty`        | O(1)            | O(1)           | —                |
// | **Overall**    | —               | O(1) **avg.**  | O(n)             |


class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
    }
    // keep push O(1) and do the pop and top as O(n)(ocasionally) but O(1) amortized
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    cout << "Popped element: " << param_2 << endl;
    cout << "Peeked element: " << param_3 << endl;
    cout << "Is queue empty? " << (param_4 ? "Yes" : "No") << endl;
    return 0;
}