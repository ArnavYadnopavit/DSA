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
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
         ListNode* one=head , *two=head;
         while(two!=nullptr && two->next!=nullptr){
            one=one->next;
            two=two->next->next;
            if(one==two) return true;
         }
         return false;
    }
};
