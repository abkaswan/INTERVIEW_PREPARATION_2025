// time complexity : O(N*leaves) ,we traverse through the N for frogs array, inner loop we make approx L/frog[i] jumps total time = L/frogs[i] sum from 0 to N-1 , in worst case if frogs[i]=1 it becomes O(N*leaves) 
// space complexity : O(leaves) , leaves for vector of leaves size

// intution : With your “skip if v[frogs[i]] is already true” check, you are effectively implementing a sieve‐like pattern: as soon as a smaller frog’s step size has already marked the exact position k = frogs[i], you know that all multiples of k have also already been covered, so you skip the entire inner loop for that frog.

#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        int count = 0;
        vector<bool> v(leaves+1,0);
        for(int i = 0;i<N;i++){
            // we will go to next for loop only when we have not been visited to that particular leaf maybe
            if(frogs[i]<=leaves && !v[frogs[i]]){
            for(int j = frogs[i];j<=leaves;j+=frogs[i]){
                v[j]=true;
            }}
        }
        
        for(int i = 1;i<=leaves;i++)
            if(!v[i]) count+=1;
        return count;
    }
};
int main() {
    int N = 3, leaves = 4;
    int frogs[] = {2, 3, 4};
    Solution ob;
    cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    return 0;
}
