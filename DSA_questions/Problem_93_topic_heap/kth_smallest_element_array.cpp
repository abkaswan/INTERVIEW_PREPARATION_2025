#include <iostream>
#include <vector>
using namespace std;
// you can also use priority queue like array2 solution or use quickselect algorithm like we did in problem 92 and there is one more solution if max_element == size of the array or similar then use counting sort approach
// time complexity : O(n + k log n)
// space complexity : O(1) since we are modifying the input array in place.
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    // heapify or bubble down as we call it , building a min heap
    void heapify(int i ,int n, vector<int>&arr)
    {
        while(i<n){
            int longest = i;
            int l = 2*i+1;
            int r = 2*i+2;
            if(l<n && arr[l]<arr[longest])
                longest = l;
            if(r<n && arr[r]<arr[longest])
                longest = r;
            if(longest!=i){
                swap(arr[longest],arr[i]);
                i = longest;
            }
            else{
                break;
            }
        }        
    }
    int kthSmallest(vector<int> &arr, int k) {
        // method 1 : using min heap directly 
        int n = arr.size();
        for(int i=(n/2)-1;i>=0;i--){
            heapify(i,n,arr);
        }
        // pop from the arr and heapify again for this
        while(k--){
            swap(arr[0],arr[n-1]);
            --n;
            heapify(0,n,arr);
        }
        return arr[n];
    }
};
int main() {
    Solution sol;
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "Kth smallest element is: " << sol.kthSmallest(arr, k) << endl;
    return 0;
}