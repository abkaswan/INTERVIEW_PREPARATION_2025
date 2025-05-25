#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class MinStack {
private:
    vector<pair<int,int>>v;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()) v.push_back({val,val});
        else{
            int minVal = min(val,v.back().second);
            v.push_back({val,minVal});
        }
    }
    
    void pop() {
        if(!v.empty()) v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout<<obj.getMin()<<endl;
    obj.pop();
    cout<<obj.top()<<endl;
    cout<<obj.getMin()<<endl;
    return 0;
}
