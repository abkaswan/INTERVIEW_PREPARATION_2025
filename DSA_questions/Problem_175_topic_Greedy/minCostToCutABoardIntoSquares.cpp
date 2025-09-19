// Precise exchange argument --->

// Suppose at some point you have h horizontal segments and v vertical segments, and you must choose between:
// 1.  a vertical cut with raw cost a (i.e. a = x[i]), or
// 2.  a horizontal cut with raw cost b (i.e. b = y[j]).

// If you do vertical (a) first, then horizontal (b):
// cost if vertical then horizontal = a*h + b*(v+1)
// = a*h + b*v + b.

// If you do horizontal (b) first, then vertical (a):
// cost if horizontal then vertical = b*v + a*(h+1)
// = b*v + a*h + a.

// Difference:
// cost(vert then horiz) - cost(horiz then vert)
//  = (a*h + b*v + b) - (b*v + a*h + a)
//  = b - a

// So doing vertical then horizontal is cheaper precisely when b - a < 0, i.e. when a > b. 
// In other words: pick the larger raw cost first.

// That algebraic result is why the standard greedy is:
// 1. sort both arrays descending,
// 2. at each step compare x[i] and y[j] (the raw costs), not h*x[i] and v*y[j].

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity : O(m log m + n log n) for sorting + O(m+n) for the while loop
// space complexity : O(1)

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        int h = 1, v = 1, startX = 0, startY = 0;
        long long minCost = 0;
        sort(x.rbegin(),x.rend());
        sort(y.rbegin(),y.rend());
        // startX is for rows and startY is for columns
        while(startX<x.size() && startY<y.size()){
            long long val1 = (long long) h*x[startX]; //vertical cut here
            long long val2 = (long long) v*y[startY]; // horizontal cut here
            if(x[startX]>y[startY]){
                
                minCost+=val1;
                startX++;
                v++;
            }
            else{
                minCost+=val2;
                startY++;
                h++;
            }
        }
        // finish startX
        while(startX<x.size()){
            minCost+=(long long) (h*x[startX]);
            startX++;
            v++;
        }
        // finish startY
        while(startY<y.size()){
            minCost+=(long long) (v*y[startY]);
            startY++;
            h++;
        }
        return (int)minCost;
    }
};

int main(){
    Solution sol;
    vector<int> x = {2,1,3};
    vector<int> y = {4,1,2};
    cout<<sol.minCost(3,3,x,y)<<endl;
    return 0;
}