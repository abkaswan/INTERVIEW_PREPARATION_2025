#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
public:
    //tc : O(n) and sc : O(1) kind of kdane algorithm 
    // or you can use two pointer approach also 
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX,maxProfit = -1,res=0;
        for(int i = 0;i<prices.size();i++){
            //updating minPrice
            minPrice = min(minPrice,prices[i]);
            //updating maxProfit
            maxProfit = max(maxProfit,prices[i]-minPrice);
            
        }
        return maxProfit;
    }

};
int main() {
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<s.maxProfit(prices);
    return 0;
}
