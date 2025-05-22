#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // dp : bottom up approach , using table - it will be done iteratively in that case so no extra recursive stack memory and it will be done in O(n^2) and O(n^2) tc and sc but little bit faster from top down dp
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        // rows represent the index and columns indicate the countOfBrackets
        // dp[i][j] -> is it possible to reach index i (the first i chars) with j opening brackets 
        // i = 0 means no chars processed , i = n means n characters processed , so result would be dp[n][0]
        dp[0][0] = true; // can we reach index 0 to with 0 opening brackets ofcourse 
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==false) continue;
                //now if it true then we see which other conditions will be true for the upcoming index i+1 , 
                // in case of ( it would be that if j brackets for ith index is possible then i+1 j+1 brackets would be opened , 
                // for the ) , if dp[i][j]==true then it would close one bracket so next dp[i+1][j-1] = true
                // in case of * , dp[i+1][j-1],dp[i+1][j] and dp[i+1][j+1] all could be true
                if(s[i]=='(')
                {
                    dp[i+1][j+1]=true;
                }
                else if(s[i]==')')
                {
                    if(j>0)
                        dp[i+1][j-1]=true;
                }
                else{
                    dp[i+1][j+1]=true; // if we take * as (
                    dp[i+1][j]=true; // if we take * as ''
                    if(j>0)
                        dp[i+1][j-1]=true; // if we take * as )

                }
            }
        }
        return dp[n][0];

    }
};
int main() {
    Solution sol;
    string s;
    cin >> s;
    bool result = sol.checkValidString(s);
    cout << result << endl;
    return 0;
}
