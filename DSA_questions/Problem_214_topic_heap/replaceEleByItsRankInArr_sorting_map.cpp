#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*
Time Complexity:
- Copying arr to arr2: O(N)
- Sorting arr2: O(N log N)
- Assigning ranks: O(N)
- Building result: O(N)
=> Overall: O(N log N)

Space Complexity:
- arr2 copy: O(N)
- unordered_map (ranks): O(N)
- result vector: O(N)
=> Overall: O(N)
*/

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        // method 1 : sort it in another vector and rank it 
        
        // step 1 : build new array, copy arr there and sort it
        vector<int> arr2(arr); // O(n) time and space
        sort(arr2.begin(),arr2.end()); // O(nlogn) time and O(1) space
        
        // step 2 : rank it
        unordered_map<int,int> rank; // value,rank -- O(n) time and space
        int count = 1;
        for(int i = 0;i<N;i++){
            if(rank.find(arr2[i])==rank.end()){
                rank[arr2[i]] = count++;
            }
        }
        
        // step 3 : build res using original vector -- O(n) time and space
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
