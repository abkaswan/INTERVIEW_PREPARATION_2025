#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
public:
    //tc : O(n) and sc : O(1)
    int maxProfit(vector<int>& prices) {
        // buy one stock and different day sell that stock , so return max-min or in -ve case return 0
        // always moving forward only can happen so after the min , max should come that's how the stock market works
        // not always the min , max will depend on the min and everytime we will udpate the answer when we have both max and min
        int mini = INT_MAX,maxi = -1,res=0;
        for(int i = 0;i<prices.size();i++){
            //updating mini
            if(mini>prices[i]){
                mini = prices[i];
                maxi = -1;
            }//afer updating mini only we are taking into account the maxi value
            else{
                maxi=max(maxi,prices[i]);
                res = max(res,maxi-mini);
            }
        }
        return res;
    }

};
int main() {
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<s.maxProfit(prices);
    return 0;
}
