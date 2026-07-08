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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1,head);
        ListNode* prv=nullptr,*cur=head,*nxt=head->next;
        ListNode* kth_ptr=cur;
        
        ListNode* loopdummy=dummy;
        while(kth_ptr){
            for(int i=1;i<k;i++){
                kth_ptr=kth_ptr->next;
                if(!kth_ptr) break;
            }
            if(!kth_ptr) break;
            while(prv!=kth_ptr){
                cur->next=prv;
                prv=cur;
                cur=nxt;
                if(nxt) nxt=nxt->next;
            }
            kth_ptr=cur;
            ListNode* temp = loopdummy->next;
            loopdummy->next=prv;
            temp->next=cur;
            loopdummy = temp;
            prv=nullptr;
        }
        return dummy->next;
    }
};
