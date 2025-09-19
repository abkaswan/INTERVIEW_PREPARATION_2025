#include<iostream>
#include<vector>
using namespace std;
// time complexity : O(n log n) --> merge sort with counting
// space complexity : O(n) --> for the temporary array used in merging

class Solution {
  public:
    int count = 0;
    void merge(int l,int r,int mid,vector<int>&arr){
        vector<int> temp;
        int low = l, high = mid+1;
        while(low<=mid && high<=r){
            if(arr[low]>arr[high]) {
                // here is the part where the count will happen also , if one element is like that then all the element after that low are also like that because the array is sorted right
                count+=(mid-low+1);
                temp.push_back(arr[high++]);
            }
            else temp.push_back(arr[low++]);
        }
        //remaing elements from both of the points 
        while(low<=mid){
            temp.push_back(arr[low++]);
        }
        while(high<=r){
            temp.push_back(arr[high++]);
        }
        for(int i = l;i<=r;i++){
            arr[i] = temp[i-l];
        }
    }
    void mergeSort(int l, int r, vector<int>& arr){
        if(l>=r) return;    
        int mid = l+(r-l)/2;
        mergeSort(l,mid,arr);
        mergeSort(mid+1,r,arr);
        merge(l,r,mid,arr);
    
    }
    int inversionCount(vector<int> &arr) {
        // second method : use merge sort for this
        int n = arr.size();
        mergeSort(0,n-1,arr);
        return count;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {2, 3, 8, 6, 1};
    cout << sol.inversionCount(arr) << endl; // Output: 5
    return 0;
}