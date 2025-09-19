#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n)
// space complexity : O(1)
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // so how do you find two elements , one that is missing and one that is repeating twice think
        // math , that is the answer
        // first equation would be sum of numbers :  1,2,3...n = n(n+1)/2
        // second equation would be sum of square of numbers : 1^2,2^2.....n^2 = n(n+1)(2n+1)/6
        int n = arr.size();

        // expected values
        long long expectedSum = 1LL * n * (n + 1) / 2;
        long long expectedSquareSum = 1LL * n * (n + 1) * (2LL * n + 1) / 6;
        
        // actual values
        long long sum = 0,squareSum = 0;
        
        for(auto ele : arr){
            sum+=ele;
            squareSum+=(1LL*ele*ele);
        }
        
        // x-y will come from here ; where x=missing number , y= repeating number
        long long diffXY = expectedSum-sum;
        // x^2-y^2 will come from here
        long long diff2 = (expectedSquareSum-squareSum);
        long long sumXY = diff2/diffXY;
        
        // now derive x and y frmo them 
        long long x = (diffXY+sumXY)/2;
        long long y = sumXY-x;
        
        return {(int)y,(int)x};
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}