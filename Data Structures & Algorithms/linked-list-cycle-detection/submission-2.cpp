/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        //if empty or just one element then no cycle
        if(!head || head->next==nullptr) return false;

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;//moves 1 place
            fast=fast->next->next;//moves 2 places
            if(slow==fast) return true;//cycle exists
        }
        return false;
        
    }
};
