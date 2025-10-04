#include<iostream>
using namespace std;
// monotonic stack -- increasing stack
// this is used to get the next smaller element in the stack and previous smaller element

// monotonic stack -- decresing stack
// this is used to get the next greater element in the stack and previous greater element

int main(){
    vector<int> v = {1,3,10,7,5,24,4};
    cout<<"array elements : ";
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;

    stack<int> s;
    vector<int> nge(v.size(),-1);
    vector<int> pge(v.size(),-1); 
    // monotonic stack -- decreasing stack
    // method 1 : decreasing stack - previous greater element
    cout<<"-------------------------method 1 : decreasing stack - previous greater element-------------------------"<<endl;
    for(int i = 0;i<v.size();i++){
        
        // for pge we will use this condition
        while(!s.empty() && v[s.top()]<=v[i]){
            s.pop();
        }
        pge[i] = s.empty()?-1:s.top();
        s.push(i);
    }
    cout<<"previous greater elements array: ";
    for(auto x: pge){
        cout<<x<<" ";
    }
    cout<<endl;
    // reseting the stack
    while(!s.empty()) s.pop();

    // method 2 : decreasing stack - next greater element
    cout<<"-------------------------method 2 : decreasing stack - next greater element-------------------------"<<endl;
    while(!s.empty()) s.pop();
    for(int i = v.size()-1;i>=0;i--){

        // for nge we will use this condition
        while(!s.empty() && v[s.top()]<=v[i]){
            s.pop();
        }
        nge[i] = s.empty()?-1:s.top();
        s.push(i);
    }
    cout<<"next greater elements array: ";
    for(auto x: nge){
        cout<<x<<" ";
    }
    cout<<endl;

    // reseting the stack
    while(!s.empty()) s.pop();
    // since we are using next greater element again so emptying that vector nge also
    fill(nge.begin(), nge.end(), -1);
    
    // method 3 : array fill -- will use next greater element only for this one
    // so always think about how you want to find out nge/pge either by i=0 or i=n-1 and based on that the condition would change but one thing is for sure we wil always try to build the monotonic decreasing stack
    // one more thing when we were doing i=n-1 to 0 we were filling the nge for each index i , in this we will fill for index s.top()
    cout<<"-------------------------method 3 : array fill and starting from i=0 to n-1-------------------------"<<endl;
    for(int i = 0;i<v.size();i++){
        while(!s.empty() && v[s.top()]<v[i]){
            nge[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    cout<<"next greater elements array: ";
    for(auto x: nge){
        cout<<x<<" ";
    }
    cout<<endl;

    // reseting the stack
    while(!s.empty()) s.pop();
    // resetting both nge and pge
    fill(nge.begin(), nge.end(), -1);
    fill(pge.begin(), pge.end(), -1);

    // method 4 : both next greater and previous greater element
    // but here is a catch you either will get (next greater,previous greater or equal) elements OR (next greater or equal, previous greater) elements
    // because we are using i = 0 to n-1 that's why 
    cout<<"-------------------------method 4 : both next greater and previous greater element-------------------------"<<endl;
    for(int i = 0;i<v.size();i++){
        // because see here we are using < not <= and that is because we also want to know nge along with pge so we need to sacrifice this
        while(!s.empty() && v[s.top()]<v[i]){
            nge[s.top()] = i;
            s.pop();
        }
        pge[i] = s.empty()?-1:s.top();
        s.push(i);
    }
    cout<<"next greater elements array: ";
    for(auto x: nge){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"previous greater elements array: ";
    for(auto x: pge){
        cout<<x<<" ";
    }
    cout<<endl;

}