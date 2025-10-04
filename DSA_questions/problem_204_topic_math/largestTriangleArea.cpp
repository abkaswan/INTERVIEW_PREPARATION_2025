#include<iostream>
#include<vector>
using namespace std;

// time complexity : O(n^3) and space complexity : O(1)
class Solution {
public:
    double calculateArea(vector<int> A,vector<int> B,vector<int> C){
        int x1 = A[0], y1 = A[1];
        int x2 = B[0], y2 = B[1];
        int x3 = C[0], y3 = C[1];
        return abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        // use brute force : O(n^3)
        // formula is this - A = 1/2 |x₁(y₂ - y₃) + x₂(y₃ - y₁) + x₃(y₁ - y₂)|
        double max_area = 0;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    double area = calculateArea(points[i],points[j],points[k]);
                    max_area = max(max_area,area);
                }
            }
        }
        return max_area;
    }
};
int main(){
    Solution s;
    vector<vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    cout<<s.largestTriangleArea(points);
    return 0;
}