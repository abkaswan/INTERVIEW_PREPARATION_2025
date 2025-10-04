#include<iostream>
#include<queue>
#include<stack>
using namespace std;
// time complexity O(n) and space complexity O(n)
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // first in first out
        // popped element is 5 10 15 20 25 -- if in this order we keep it in stack it works so use stack for this problem solved
        // method 1 : using stack
        stack<int> s;
        while(!q.empty())
        {
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            q.push(s.top());s.pop();
        }
    }
};
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    Solution obj;
    obj.reverseQueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}