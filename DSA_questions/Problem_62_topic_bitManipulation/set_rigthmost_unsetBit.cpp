#include <iostream>
#include <cmath>
using namespace std;
// time complexity : O(logn) = Each iteration divides n by 2 → total iterations = number of bits in n = O(log n)
// space complexity : O(1) = Only a constant amount of space is used for variables
class Solution {
  public:
    int setBit(int n) {
     // it means go from right to left and wherever you encounter 0 for the first time convert it to 1 and then give the number for that
     int res=0,flag = 0,base = 1;
     while(n>0){
         int temp = n%2;
         if(temp==0 && flag == 0)
         {
             temp = 1;
             flag = 1;
         }
         res+=temp*base;
         base*=2;
         n=n/2;
     }
     if(flag == 0){
         res+=1*base;
     }
     return res;
        
    }
};
int main() {
    Solution sol;
    int n = 18; // Example input
    int result = sol.setBit(n);
    std::cout << "Result: " << result << std::endl; // Expected output: 19
    return 0;
}