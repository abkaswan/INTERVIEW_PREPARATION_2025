#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n + max_element)
// space complexity : O(max_element) for count array
class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {
        // Find maximum element
        int max_element = arr[0];
        for(int num : arr) {
            max_element = max(max_element, num);
        }
        
        // Create count array
        vector<int> count(max_element + 1, 0);
        
        // Count frequencies
        for(int num : arr) {
            count[num]++;
        }
        
        // Find kth element
        int counted = 0;
        for(int i = 0; i <= max_element; i++) {
            counted += count[i];
            if(counted >= k) {
                return i;
            }
        }
        return -1; // Should never reach here given constraints
    }
};
int main() {
    Solution sol;
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "Kth smallest element is: " << sol.kthSmallest(arr, k) << endl;
    return 0;
}