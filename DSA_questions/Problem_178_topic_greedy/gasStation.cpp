#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n) and space complexity : O(1)
// curr checks local feasibility 
// total checks global feasibility

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int curr = 0,total = 0,ans = 0;
        // total checks if possible at all.
        // curr checks if your current try is failing.
        // When it fails, skip to the next station because all earlier ones are worse.
        // The last reset point is the correct answer
        for(int i = 0;i<n;i++){
            total+=(gas[i]-cost[i]);
            curr+=(gas[i]-cost[i]);
            // if curr ever drops reset start to i+1
            if(curr<0){
                curr = 0;
                ans = i+1;
            }
        }
        
        // if total gas < total cost answer is always -1
        return (total>=0)?ans:-1;
    }
};
int main() {
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int result = sol.startStation(gas, cost);
    cout << "Starting gas station index: " << result << endl; // Output: 3
    return 0;
}