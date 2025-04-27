#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n*k)
// Space Complexity: O(k)​ -- using single dp array only by storing and using previous values by going to
class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<int> dp(k+1,0); // dp to store the values 
        dp[0]=1;
        for(int i = 1;i<=n;i++){
            for(int j = k;j>=arr[i-1];j--)
            {
                dp[j]+=dp[j-arr[i-1]];
            }
        }
        return dp[k]?true:false;
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