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
    void reorderList(ListNode* head) {
        //find the mid
        ListNode* slow=head;
        ListNode* fast=head->next;
        if(!head || !head->next || !head->next->next) return;
        while(fast && fast->next)//if 1 el then no fast exists , if 2 el then also no reordering can be done
        {
            //Floyd's algo
            slow=slow->next;
            fast=fast->next->next;
        }
        //reverse the second part
        ListNode* prev=nullptr;
        ListNode* curr=slow->next;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        slow->next=nullptr;//cut the first half

        //merge the two lists
        ListNode* first=head;
        ListNode* second=prev;
        while(second){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;

        }

        

        
    }
};
