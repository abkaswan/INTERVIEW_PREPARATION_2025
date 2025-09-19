#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n) and space complexity : O(n)
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        // for(int i = 1;i<n;i++){
        //     v.push_back(i);
        // }
        // v.push_back((1-n)*n/2);
        for(int i = 1;i<=n/2;i++){
            v.push_back(i);
            v.push_back(-i);
        }
        if(n%2==1) v.push_back(0);
        return v;


    }
};
int main() {
    Solution sol;
    vector<int> result = sol.sumZero(5);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}