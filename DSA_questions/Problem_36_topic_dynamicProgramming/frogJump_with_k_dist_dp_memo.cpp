#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
// for the below code dp[i] tells us how much minimum cost it takes to reach the last stone starting from index i , 
// so dp[3] from i = 3 to reach last index what was the minimum cost ? using dp[i]=mini we are storing it at each stage , at the first it will save the last index dp[4] if n = 5 why because each time we are calling a recursion and it will end if we reach something like that no ? then dp[3] dp[2] dp[1] etc . 

int frog(int n, int k, vector<int>& h,int i,vector<int>& dp){
    if(i==n-1) return 0;
    int mini = INT_MAX;
    if(dp[i]!=-1) return dp[i];
    for(int j = 1;j<=k;j++)
    {
        int nxt = i+j;
        if(nxt<n){
            mini = min(mini,abs(h[nxt]-h[i])+frog(n,k,h,nxt,dp));
        }
    }
    return dp[i]=mini;
}
// Function to compute the minimum total cost
int solve(int N, int K, vector<int>& heights){
    // method 2 : memoisation approach
    // time complexity : O(N*K) for each position we try K jumps
    // space complexity : O(2N) - max depth of recursion call stack O(N) and O(N) for dp array
    vector<int> dp(N,-1);
    return frog(N,K,heights,0,dp);
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    int result = solve(N, K, heights);
    cout << result << endl;

    return 0;
}
