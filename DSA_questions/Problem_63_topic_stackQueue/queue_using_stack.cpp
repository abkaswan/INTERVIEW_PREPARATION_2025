#include <iostream>
#include <stack>
using namespace std;

// time complexity : O(n) for push, O(1) for pop, O(1) for peek, O(1) for empty
// space complexity : O(n) for storing elements in stack , 
// Here n is the current number of elements in the stack so far.
// | Operation | Time Complexity | Space Complexity |
// | --------- | --------------- | ---------------- |
// | `push`    | O(n)            | O(n)             |
// | `pop`     | O(1)            | O(1)             |
// | `peek`    | O(1)            | O(1)             |
// | `empty`   | O(1)            | O(1)             |

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
    }
    
    void push(int x) {
        // now here first see if s1 is empty , if not empty it move that to stack s2
        // then push in stack s1 and then move back elements in s1 from s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
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