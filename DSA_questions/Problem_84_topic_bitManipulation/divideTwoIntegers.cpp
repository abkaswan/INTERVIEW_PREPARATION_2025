#include <iostream>
#include <limits.h>
using namespace std;
// time complexity : O(log(n))
// space complexity : O(1)
// Problem: Divide two integers without using multiplication, division, or mod operator.
class Solution {
public:
    int divide(int dividend, int divisor) {
        // simplest method will be using negative 
        // example : 10,3 so do 10-3 possible yes so count=1
        // 7,3 so do 7-3 possilbe yes so count = 2
        // 4,3 do 4-3 possible yes so count = 3
        // 1,3 do 1-3 possible no so return 3
        // but one issue in worst case where dividend >>>> divisor ex: divident = 2^30 and divisior = 1 , it is almost O(2^30) right so not good soultion 

        // another solution is dividing by 2 each step 
        // 10,3 so div = 3 , do div*2 till did-div is possible
        // 10,6 so now 10-6 = 4 , new pair (4,3) , do div*2 til did-div is possible , result = 2 (2 steps we have taken right 3->6->12)
        // 4,3 only so 4-3 = 1, new pair (1,3), result = 2+1 = 3,  now no more so result is total steps 3

        // write it in writing now then 
        //base case : according to the condition this should happen
        if(dividend==1<<31 && divisor==-1) return INT_MAX;
        bool negative = (dividend<0) ^ (divisor<0);
        // now take only positive numbers from both of them 
        long long dvd = abs((long long) dividend);
        long long div = abs((long long) divisor);
        long long result = 0;
        
        while(dvd - div >= 0){
            int count = 0;
            while(dvd - (div<<1<<count) >=0){
                count++;
            }
            result+=(1<<count);
            dvd -= (div<<count);
        }

        if(negative)
            result = -result;
        return result;
    }
};
int main() {
    Solution sol;
    int dividend = 10, divisor = 3;
    int result = sol.divide(dividend, divisor);
    cout << "Result of " << dividend << " / " << divisor << " is: " << result << endl; // Output should be 3
    return 0;
}
