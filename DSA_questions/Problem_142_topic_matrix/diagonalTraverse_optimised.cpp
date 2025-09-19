#include <iostream>
#include <vector>
using namespace std;
// time complexity: O(m*n)
// space complexity: O(1)
class Solution {
public:
    // how the equation for row and col came to be : 
    // We want the range of valid row indices i for a given diagonal index d.
    // Step 1: Relationship between i and j
    //     For a diagonal d:
    //         j=d−i
    //     Because i + j = d.

    // Step 2: Apply column constraints
    //     We need 0 ≤ j < n. Substitute j = d - i:
    //         0≤d−i<n
    //     This breaks into two inequalities:
    //         0≤d−i → i≤d
    //         d−i<n → i>d−n → i≥d−(n−1)
    //     So from column bounds:
    //         d−(n−1)≤i≤d
    
    // Step 3: Apply row constraints
    //     We also need 0 ≤ i < m. So: 0≤i≤m−1
    
    // Step 4: Combine constraints
    //     Now take the intersection of both conditions:
    //         max(0,d−(n−1))≤i≤min(m−1,d)
    // and in the same way it will happen for j also .

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        vector<int> res;
        res.reserve(m*n);
        // total diagonals is m+n-1 right so used it , also remember i+j = d for diagonals 
        for(int d = 0;d<m+n-1;d++){
            int r,c;
            if(d%2==0){
                // means the diagonal is even so go up right , for going up right we will need to start from bottom-left cell right so we wil need to calculate the row first ,and for row also what can be the max value for that so from this equation : max(0,d−(n−1))≤i≤min(m−1,d)
                r=min(m-1,d);
                c=d-r;
                while(r>=0 && c<n){
                    res.push_back(mat[r][c]);
                    r--;
                    c++;
                }
            }
            else{
                // means the diagonal is odd so we need to go down left , for going down left we will need to start from top-right position right so we will need to calculate the col first, and for col also what can be the max vlaue for that so from this equatoin : max(0,d−(m−1))≤j≤min(n−1,d)
                c = min(n-1,d); // here also we can use min row we can use because top-right position right so max(0,d−(n−1)) would also work and vice versa for col also 
                r = d-c;

                // r = max(0,d-(n-1));
                // c = d-r;
                while(c>=0 && r<m){
                    res.push_back(mat[r][c]);
                    r++;
                    c--;
                } 
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result = sol.findDiagonalOrder(mat);
    cout << "Diagonal traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
