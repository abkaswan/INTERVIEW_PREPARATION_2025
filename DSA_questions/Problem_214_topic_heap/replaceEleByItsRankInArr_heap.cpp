#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

/*
Time Complexity:
- Building the heap (N insertions): O(N log N)
- Assigning ranks by popping heap: O(N log N)
- Building result: O(N)
=> Overall: O(N log N)

Space Complexity:
- priority_queue (heap storage): O(N)
- unordered_map (ranks): O(N)
- result vector: O(N)
=> Overall: O(N)
*/


class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        // method 2 : heap operation -- min heap gives values in ascending order
        priority_queue<int,vector<int>,greater<int>> pq; 
        for(int x : arr){
            pq.push(x);
        }
        
        // step 2 ; use map to store the rank
        unordered_map<int,int> rank;
        int count = 1;
        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            if(rank.find(val)==rank.end()) rank[val] = count++;
        }
        
        // step 3 : build the res using original arrya
        vector<int> res(N);
        for(int i = 0;i<N;i++){
            res[i] = rank[arr[i]];
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> arr = {5, 2, 5, 3, 2, 3, 5, 5};
    int N = arr.size();
    vector<int> res = s.replaceWithRank(arr, N);
    for(int i = 0;i<N;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
