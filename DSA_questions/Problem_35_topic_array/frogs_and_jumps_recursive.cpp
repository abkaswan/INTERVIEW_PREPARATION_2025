// time complexity : O(N*leaves) ,we traverse through the N for frogs array, inner loop we make approx L/frog[i] jumps total time = L/frogs[i] sum from 0 to N-1 , in worst case if frogs[i]=1 it becomes O(N*leaves) 
// space complexity : O(leaves+N) , leaves for vector of leaves size and N for recursion call stack
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void uni(int n, int i,int frogs[],vector<int>& v,int leaves)
    {
        // also base condition is when we covered all the frogs 
        if(i>=n) return ;
        for(int j = frogs[i];j<=leaves;j+=frogs[i]){
            v[j]=1;
        }        
        //move to the next frog
        uni(n,i+1,frogs,v,leaves);
        
    }
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        int count = 0;
        vector<int> v(leaves+1,0);
        uni(N,0,frogs,v,leaves);
        for(int i = 1;i<=leaves;i++)
            if(v[i]==0) count+=1;
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
