#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
// for the below code dp[i] tells us how much minimum cost it takes to reach the last stone starting from index i , 
// so dp[3] from i = 3 to reach last index what was the minimum cost ? using dp[i]=mini we are storing it at each stage , at the first it will save the last index dp[4] if n = 5 why because each time we are calling a recursion and it will end if we reach something like that no ? then dp[3] dp[2] dp[1] etc . 

// Function to compute the minimum total cost
int solve(int N, int K, vector<int>& heights){
    // method 3 : tabulation approach
    // time complexity : O(N*K) for each position we try K jumps
    // space complexity : O(N) - O(N) for dp array
    vector<int> dp(N,INT_MAX);
    dp[N-1]=0;
    for(int i = N-2;i>=0;i--){
        for(int j = 1;j<=K && i+j<N;j++){
            dp[i] = min(dp[i],abs(heights[i+j]-heights[i])+dp[i+j]);
        }
    }
    return dp[0];
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
