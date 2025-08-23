#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity : O(n log n) for sorting
// space complexity : O(n) for storing the end and start times in a vector of pairs
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // ok hint is think about the end time , if a meeting starts and ends only then we will be able to hold another meeting right ?
        // so sort it based on the end time , why not start time ? 
        // because let's say there is a meeting starts at 4 and ends at 8 but another meeting is there that starts at 5 but ends at 6 then obviously 
        // if there is another meeting in the remaining time 6 - 8 can be held if not both the count will anyway be the same. right ? 
        // so this is the greedy aproach for this problem 
        
        // step1 : sorted based on the end date
        vector<pair<int,int>> v;
        int n = end.size();
        for(int i = 0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        
        //step2 : greedily pick the answer
        int count = 1;
        int curr_end = v[0].first; // first = end time
        for(int i = 1;i<n;i++){
            if(curr_end<v[i].second){ // second = start time
                count+=1;
                curr_end = v[i].first;
                
            }    
        }
        return count;
        
    }
};
int main() {
    Solution sol;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << "Maximum number of meetings: " << sol.maxMeetings(start, end) << endl;
    return 0;
}