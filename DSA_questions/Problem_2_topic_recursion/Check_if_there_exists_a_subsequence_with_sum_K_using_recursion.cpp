#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(2ⁿ)
// Space Complexity: O(n)​
class Solution {
  public:
    bool fun(int n, vector<int>& arr, int k,int i,int sum)
    {
        // first using recursion it will take : O(2^n) in worst case , sc: O(n) worst case the stack will have at most n elements
        if(sum>k || i==arr.size()){
            if(sum==k) return true;
            return false;
        }
        // if we include the element || if we don't include the element
        return fun(n,arr,k,i+1,sum+arr[i]) || fun(n,arr,k,i+1,sum);;
        
        
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return fun(n,arr,k,0,0);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}