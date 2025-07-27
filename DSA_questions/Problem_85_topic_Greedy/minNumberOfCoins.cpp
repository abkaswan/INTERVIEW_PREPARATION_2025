#include <iostream>
#include <vector>
using namespace std;
// Function to find the minimum number of coins required to make change for N
// time complexity: O(N)
// space complexity: O(N) for result vector
class Solution {
  public:
    vector<int> minPartition(int N) {
        // check which number after the N lies and then
        // do N-number till it is less than that , repeat the process
        vector<int> v;
        vector<int> d = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        
        for(int coin : d){
            while(N>=coin){
                N = N-coin;
                v.push_back(coin);
            }
        }
        return v;
    }
};
int main() {
    Solution sol;
    int N = 93;
    vector<int> result = sol.minPartition(N);
    cout << "Minimum coins required for " << N << " are: ";
    for (int coin : result) {
        cout << coin << " ";
    }
    cout << endl;
    return 0;
}