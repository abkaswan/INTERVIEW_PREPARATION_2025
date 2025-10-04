#include <iostream>
#include <vector>
using namespace std;
// time complexity : O(n) , space complexity : O(1)
class Solution {
public:
    int trap(const vector<int>& height) {
        int n = height.size();
        // method 2 - use two pointers approach : instead of globalmaxLeft and globalmaxRight arrays you took in method 1
        // let's assume we have indexes like : 0,left,suspect,right,n-1
        // here one doubt you may have , what if there is one point suspect where the value of it is less than that of left , but we are picking left here ? , it doesn't matter in this case because we need globalMaxLeft and globalMaxRight remember and from both of them we will take min here , so we will pick leftMax value because that is minimum because leftMax<=arr[left]<=arr[right] 
        // second case : what if there is one point suspect where the value of it is greater than that of left, but we are pickin left here ? in this case we always pick globalMaxLeft and globaclMaxRight and their min right so here on the right Side there is a possiblity that there is a bigger number right so leftMax is the minimum from boht of them so we pick that 

        int left = 0,right = n-1;
        int leftMax = 0,rightMax = 0,res = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(leftMax<=height[left]) leftMax = height[left];
                else res+=(leftMax-height[left]);
                left++;
            }
            else{
                if(rightMax<=height[right]) rightMax = height[right];
                else res+=(rightMax-height[right]);
                right--;
            }
        }
        
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<sol.trap(height)<<endl; // Output: 6
    return 0;
}