// 36 minutes it took to solve this problem
// time complexity : O(log n)
// space complexity : O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& arr) {
        // find the part where there is a bump and return the element from there
        // there should always be ascending order and if there is bump return that , all integers are unique also
        int n = arr.size();
        int l = 0, r = n-1;
        
        while(l<r){
            int mid = l+(r-l)/2;
            if(arr[mid]>arr[r]){
                l = mid+1;
            }
            else{
                r=mid;
            }
        }
        return arr[l];
    }
};
int main() {
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    int result = sol.findMin(nums);
    cout << "The minimum element in the rotated sorted array is: " << result << endl;
    return 0;
}