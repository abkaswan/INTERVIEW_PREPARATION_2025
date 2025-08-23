#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// time complexity : O(nlogk)
// space complexity : O(k)
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // using priority queue only for this one . 
        // method 2 : using priority queue max heap 
        priority_queue<int> pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            // then pop the element from pq if i>k so the pq will only have k size
            if(i>=k)
                pq.pop();
        }
        return pq.top();
    }
};
int main() {
    Solution sol;
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int result = sol.kthSmallest(arr, k);
    cout << "The " << k << "th smallest element is: " << result << endl; // Output: 7
    return 0;
}