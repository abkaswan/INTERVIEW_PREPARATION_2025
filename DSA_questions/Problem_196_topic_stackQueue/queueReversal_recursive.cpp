#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// time complexity O(n) and space complexity O(n)
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // first in first out
        // popped element is 5 10 15 20 25 -- if in this order we keep it in stack it works so use stack for this problem solved
        // method 2 : using recursion -> if we can do using stack then we can do using recursion also 
        if(q.empty()) return;
        int x = q.front();
        q.pop();
        reverseQueue(q);
        q.push(x);
    }
};
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    Solution obj;
    obj.reverseQueue(q);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}