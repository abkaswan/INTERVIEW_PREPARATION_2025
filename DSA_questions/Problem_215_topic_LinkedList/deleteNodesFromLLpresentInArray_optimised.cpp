#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// time complexity: O(N+M) where N is the size of linked list and M is the size of array because we are traversing linked list once and during set creation we are traversing array once
// space complexity: O(M) for set
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // optimised method : use set for nums for O(1) lookup
        unordered_set<int> numsDelete(nums.begin(),nums.end());
        ListNode* dummy = new ListNode(0,head); // to simplify edge cases
        ListNode *temp = head,*prev = dummy;
        while(temp){
            if(numsDelete.find(temp->val)!=numsDelete.end()){
              // if you find it in set then you need to delete this element
              prev->next = temp->next;
              ListNode* toDelete = temp;
              temp = temp->next;
              delete toDelete;
            }
            else{
                // move forward
                prev = temp;
                temp = temp->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy; // free dummy node
        return newHead;
    }
};
int main(){
    Solution s;
    vector<int> nums1 = {1,3,4,9,5};
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);
    head1->next->next->next = new ListNode(9);
    head1->next->next->next->next = new ListNode(4);
    head1->next->next->next->next->next = new ListNode(1);
    ListNode* res1 = s.modifiedList(nums1,head1);

    while(res1){
        cout<<res1->val<<" ";
        res1 = res1->next;
    }
    cout<<endl;

    vector<int> nums2 = {2,1};
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    ListNode* res2 = s.modifiedList(nums2,head2);

    while(res2){
        cout<<res2->val<<" ";
        res2 = res2->next;
    }
    cout<<endl;

    vector<int> nums3 = {0,1,3,4};
    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(3);
    head3->next->next = new ListNode(4);
    head3->next->next->next = new ListNode(1);
    head3->next->next->next->next = new ListNode(0);
    ListNode* res3 = s.modifiedList(nums3,head3);

    while(res3){
        cout<<res3->val<<" ";
        res3 = res3->next;
    }
    cout<<endl;
}