#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// using sliding window method , window will be from l -> r
int totalFruit(vector<int>& fruits) {
    int n= fruits.size(),count=0;
    unordered_map<int,int> mpp;
    int l = 0, r = 0;
    while(r<n){
        mpp[fruits[r]]++; // increasing the count and r both
        while(mpp.size()>2){ //in this case window is not valid so we need to make it valid
            // decrese the count and increase l till we have only two distinct elements
            mpp[fruits[l]]--;
            if(mpp[fruits[l]]==0){
                //remove this key 
                mpp.erase(fruits[l]);
            }
            l++;
        }
        //udpate the count everytime 
        count = max(count,r-l+1);
        r++;
    }
    return count;
}

int main() {
    vector<int> arr = {0,0,1,2,1,2,2,2,2,3};
    cout << "Longest length with at most two distinct OR max NO of fruits you can pick = "
         << totalFruit(arr) << "\n";
    return 0;
}
