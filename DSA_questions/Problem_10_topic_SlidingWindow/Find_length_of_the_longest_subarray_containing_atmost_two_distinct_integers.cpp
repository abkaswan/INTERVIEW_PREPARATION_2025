#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int,int> mpp;
        int count = 0;
        //using sliding window method to solve this
        int l = 0,r = 0;
        while(r<arr.size()){
            mpp[arr[r]]++; //update the count for key = arr[r] , it tells us how many times/freq of that element
            while(mpp.size()>2)// if size is greater than 2, ie. window is invalid according to the question
            {
                //increase left side l till we reach a place where map size is 2 or we have two distinct elemetns only 
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0) //remvoing that key so that it doesn't include in the count
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }
            //udpate the count with latest
            count = max(count, r-l+1);
            r++;
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
