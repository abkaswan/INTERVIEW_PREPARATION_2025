#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotateRightOne(vector<int>& nums,int i,int j){
        int temp = nums[j];
        for(int k = j;k>i;k--){
            nums[k]=nums[k-1];
        }
        nums[i]=temp;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        // in place : tc and sc - O(n^2) and O(1)
        // we will do rotation of the array instead of swap
        // take two pointers and then we will swap based on that
        int nextPos = 0,nextNeg = 1;
        for(int i = 0;i<n;i++){
            if(i%2==0)
            {
                // there should be positive number here, if not find the next positive number and rotate here.
                if(nums[i]<0)
                {
                    nextPos = max(i,nextPos);
                    // find the correct next positive number
                    while(nextPos<n && nums[nextPos]<0){
                        nextPos++;
                    }
                    // now rotate one step right for the subarray nums[i,correctSign]
                    rotateRightOne(nums,i,nextPos);
                }    
            }
            else
            {
                // there should be negative number here, if not find the next negative number and rotate here.
                if(nums[i]>0)
                {
                    nextNeg = max(i,nextNeg);
                    // find the correct next negative number
                    while(nextNeg<n && nums[nextNeg]>0){
                        nextNeg++;
                    }
                    // now rotate one step right for the subarray nums[i,correctSign2]
                    rotateRightOne(nums,i,nextNeg);
                }    
            }
        }
        return nums;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-1,2,-3,4,-5,6,-7,8};
    vector<int> result = s.rearrangeArray(nums);
    for(int i = 0;i<result.size();i++)
        cout<<result[i]<<" ";
    return 0;
}
