#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Time Complexity: O(n) 
//   - Each element is pushed/popped at most once in the monotonic stacks.
//   - Final pass over the array is O(n).
// Space Complexity: O(n)
//   - Extra arrays pge[] and nge[] of size n.
//   - Monotonic stack may hold up to n elements.

class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        // so the idea is calculate the pge and lge for each index
        // now we know that arr[i] is maximum for the subarray from pge+1 to lge-1
        // and if arr[i]<=subarray length then this satisfies the condition so do max(maxLen,L-R+1)
        
        int maxLen = 0,n = arr.size();
        // steps to follow
        // step1 : calculate the pge and nge for each index
        // step2 : For each i: L = prevGreater[i] + 1, R = nextGreater[i] - 1, span = R - L + 1. If arr[i] <= span then ans = max(ans, span). Return ans (0 if none).
        
        // performing step1
        stack<int> s;
        // FOR NGE : In your Longest Subarray Length problem, you must use n, not -1, otherwise the length computation will break , because we are expressing here that : if no greater exists, then it means the subarray can extend all the way to the end of the array.
        vector<int> pge(n,-1),nge(n,n);
        // calculating pge
        for(int i = 0;i<n;i++){
            while(!s.empty() && arr[s.top()]<=arr[i]){
                s.pop();
            }
            pge[i] = s.empty()?-1:s.top();
            
            s.push(i);
        }
        // reseting the stack
        while(!s.empty()) s.pop();
        //calculating nge
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<=arr[i]){
                s.pop();
            }
            nge[i] = s.empty()?n:s.top();
            
            s.push(i);
        }
        
        // performing step2
        for(int i = 0;i<n;i++){
            int L = pge[i]+1;
            int R = nge[i]-1;
            int len = R-L+1;
            if(arr[i]<=len){
                maxLen = max(maxLen,len);
            }
            
        }
        
        return maxLen;
    }
};
int main(){
    Solution sol;
    vector<int> v = {10,8,2,1,2,4,7,2};
    cout<<"array elements : ";
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
    int ans = sol.longestSubarray(v);
    cout<<"longest subarray length where maximum element is less than or equal to the length of the subarray is : "<<ans<<endl;
    return 0;
}