#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity O(nlogn) space complexity O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // it might not be in order so make it in order first by sorting based on the end time
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        // now check if it is overlapping
        for(int i = 0;i<intervals.size();i++){
            if(result.back()[1]>=intervals[i][0]){
                // merge the intervals
                result.back()[1] = max(result.back()[1],intervals[i][1]);
            }
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = sol.merge(intervals);
    for (const auto& interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}