#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
Time Complexity:
- Building vector of pairs: O(N)
- Sorting pairs by value: O(N log N)
- Assigning ranks: O(N)
- Building result: O(N)
=> Overall: O(N log N)

Space Complexity:
- Vector of pairs: O(N)
- Result vector: O(N)
=> Overall: O(N)
*/

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        // method 3 : sort it in another vector with index and rank it -- can use the min heap in the same way also 
        
        // step 1 : build new array, copy arr with index there and sort it
        vector<pair<int,int>> v; 
        for(int i = 0;i<N;i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end()); // sort by value

        // step 2 : build res using original vector 
        vector<int> res(N);
        int rank = 1;
        res[v[0].second] = rank;
        for(int i = 1;i<N;i++){
            // if both are not the same values -- increase rank otherwise let it stay the same
            if(v[i].first!=v[i-1].first){
                rank++;
            }
            res[v[i].second] = rank;
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