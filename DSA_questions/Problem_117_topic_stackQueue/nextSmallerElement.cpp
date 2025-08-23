#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// time complexity: O(n)
// space complexity: O(n) for the stack
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    for(int i = 0;i<n;i++){
        while(!s.empty() && arr[i]<arr[s.top()]){
            arr[s.top()] = arr[i]; // then this is the next smaller element so push that to the 
            s.pop();
        }
        s.push(i); // push that element also

        
    }

    // for the rest of them maybe put -1?
    while(!s.empty()){
        arr[s.top()] = -1;
        s.pop();
    }
    return arr;
}
int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();
    vector<int> result = nextSmallerElement(arr, n);
    
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}