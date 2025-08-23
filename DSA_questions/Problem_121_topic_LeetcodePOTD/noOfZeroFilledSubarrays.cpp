#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n) and space complexity : O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& arr) {
        // ok so to calculate the total subarrays for x elements is x(x+1)/2
        // get the start and end index for each of the 0s here and then calcualte and return it maybe?
        int n = arr.size();
        long long count = 0;
        int start = 0;
        while(start<n){
            if(arr[start]==0){
                int end = start;
                while(end<n && arr[end]==0)
                {
                    end++;
                }
                long long len = end-start;
                count += (len*(len+1))/2;
                start = end;
            }
            else{
                start++;
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