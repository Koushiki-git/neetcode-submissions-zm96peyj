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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val;//minheap
        }
        
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=0) pq.push(lists[i]);//push the first element of the lists in pq
        }


        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            curr->next=node;
            curr=curr->next;
            if(node->next) pq.push(node->next);

        }
        return dummy->next;
        
    }
};
