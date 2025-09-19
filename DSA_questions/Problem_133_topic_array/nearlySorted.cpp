#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// time complexity: O(n log k)
// space complexity: O(k)
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // sort(arr.begin(), arr.end()); -- can use this easiest method lol
        // or
        // second solution : use priority queue -- min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = arr.size(),l=0;
        for(int i = 0;i<n;i++){
            if(i>k){
                arr[l++] = pq.top();
                pq.pop();
            }
            pq.push(arr[i]);
        }
        while(!pq.empty()){
            arr[l++] = pq.top();
            pq.pop();
            
        }
    }
};
int main() {
    Solution sol;
    vector<int> arr = {3, 1, 5, 4, 2};
    int k = 2;
    sol.nearlySorted(arr, k);
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}