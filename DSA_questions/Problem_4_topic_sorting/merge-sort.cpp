#include<vector>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
  public:
  void merge(vector<int>& arr, int l, int mid, int r){
    // the idea is that the one element arrays are already sorted right so we will start sorting the elements after that , 
    // for example we will get [5] [2] like that those are sorted already
    // but [5,2] this is not sorted , and our goal is to sort that using the l,mid,r here.
    vector<int>temp;
    int low = l;
    int high = mid+1;
    while(low<=mid && high<=r){
        if(arr[low]<=arr[high]){
            temp.push_back(arr[low++]);
        }
        else
            temp.push_back(arr[high++]);
    }
    // if some elements are still there on left side 
    while(low<=mid){
        temp.push_back(arr[low++]);
    }
    // if some elements are still there on right side
    while(high<=r){
        temp.push_back(arr[high++]);
    }
    for(int i = l;i<=r;i++){
        arr[i]=temp[i-l];
    }
}
void mergeSort(vector<int>& arr, int l, int r) {
    //divide and conquer method we will apply 
    if(l==r) return;
    int mid = l+(r-l)/2;
    mergeSort(arr,l,mid); // send the first half
    mergeSort(arr,mid+1,r); // send the second half
    merge(arr,l,mid,r); // merge them , i.e. merge the subproblems

}
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
