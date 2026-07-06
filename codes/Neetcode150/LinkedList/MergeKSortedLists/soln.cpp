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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(!k) return nullptr;
        ListNode* ret=new ListNode(-1);
        ListNode*temp=ret;
        int maxsize=0;
        priority_queue <int,vector<int>,greater<int>> pq;
        for (auto node : lists) {
            while (node) {
                pq.push(node->val);
                node = node->next;
            }
        }
        while(!pq.empty()){
            temp->next=new ListNode(pq.top());
            temp=temp->next;
            pq.pop();
        }
        return ret->next;

    }
};
