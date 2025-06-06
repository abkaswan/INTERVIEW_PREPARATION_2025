#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int frog(int n, int k, vector<int>& h,int i){
    if(i==n-1) return 0;
    int mini = INT_MAX;
    for(int j = 1;j<=k;j++)
    {
        int nxt = i+j;
        if(nxt<n){
            mini = min(mini,abs(h[nxt]-h[i])+frog(n,k,h,nxt));
        }
    }
    return mini;
}
// Function to compute the minimum total cost
int solve(int N, int K, vector<int>& heights){
    // method 1 : recursion approach
    // time complexity : O(K^N) for each position we have K choices to jump. tree has maximum depth of N , total nodes = 1+K+K^2+....+K^N = O(K^N)
    // space complexity : max depth of recursion call stack O(N)
    return frog(N,K,heights,0);
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
