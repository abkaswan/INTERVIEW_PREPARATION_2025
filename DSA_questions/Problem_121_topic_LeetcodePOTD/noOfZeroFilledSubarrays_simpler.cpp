#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n) and space complexity : O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& arr) {
        // ok so to calculate the total subarrays for x elements is x(x+1)/2
        // get the start and end index for each of the 0s here and then calcualte and return it maybe?

        // another method is : x(x+1)/2 is already x , x+1 , x+2 ... so use that
        int n = arr.size();
        long long count = 0;
        int streak = 0;
        for(auto x : arr){
            if(x==0){
                streak++;
                count+=streak;
            }
            else{
                streak = 0;
            }
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1, 3, 0, 0, 2, 0, 0, 0, 4};
    long long result = sol.zeroFilledSubarray(arr);
    cout << result << endl; // Expected output: 6
    return 0;
}