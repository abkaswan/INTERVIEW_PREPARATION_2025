#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(1) , space complexity : O(1)
class Solution {
public:
    vector<int> countDigits(int x){
        vector<int> count(10);
        while(x){
            count[x%10]++;
            x=x/10;
        }
        return count;
    }
    bool reorderedPowerOf2(int n) {
        // normally for one number if it is power of two or not we use : n&(n-1)==0 then it is otherwise it is not 
        // step 1 : but for this one we will precompute the digit frequency of this number 
        auto target = countDigits(n);
        // step 2 : digit frequency for numbers from 2^0 to 2^31 , digit frequency for those and compare 
        for(int i = 0;i<31;i++){
            if(target == countDigits(1<<i)) return true;
        }
        return false;

    }
};
int main() {
    Solution sol;
    int n = 46; // Example input
    bool result = sol.reorderedPowerOf2(n);
    cout << (result ? "True" : "False") << endl; // Output: True
    return 0;
}
