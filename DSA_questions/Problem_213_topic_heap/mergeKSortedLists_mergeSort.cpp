#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity: O(N log k)
//   N = total number of nodes in all lists
//   Recursion splits into halves (log k levels)
//   Each node is merged once per level
// Space Complexity: O(log k)
//   Due to recursion stack (depth ~ log k)
//   Merge uses in-place pointers, no extra node allocations

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* L,ListNode* R){
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(L && R){
            if(L->val>R->val){
                curr->next = R;
                R = R->next;
            }
            else{
                curr->next = L;
                L = L->next;
            }
            curr = curr->next;
        }
        curr->next = L?L:R;
        return dummy.next;
        
        
    }
    ListNode* mergeK(vector<ListNode*>& lists, int left,int right){
        if(left == right) return lists[left];
        int mid = left+(right-left)/2;
        ListNode* L = mergeK(lists,left,mid);
        ListNode* R = mergeK(lists,mid+1,right);
        // merge two merged lists (using the standard two sorted-list merge)
        return merge(L,R);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // method 2 : use merge sort for this
        if(lists.empty()) return nullptr; // handle empty input
        int n = lists.size();
        return mergeK(lists,0,n-1);

    }
};

int main() {
    Solution s;
    vector<ListNode*> lists;
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(4);
    ListNode* l3 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;

    ListNode* l4 = new ListNode(1);
    ListNode* l5 = new ListNode(3);
    ListNode* l6 = new ListNode(4);
    l4->next = l5;
    l5->next = l6;

    ListNode* l7 = new ListNode(2);
    ListNode* l8 = new ListNode(6);
    l7->next = l8;

    lists.push_back(l1);
    lists.push_back(l4);
    lists.push_back(l7);

    ListNode* root = s.mergeKLists(lists);

    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;

    return 0;
}
