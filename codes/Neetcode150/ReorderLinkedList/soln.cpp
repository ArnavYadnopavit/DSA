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
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode *temp=head->next,*prev=head,*next=temp->next;
        prev->next=nullptr;
        while(temp->next!=nullptr){
            temp->next=prev;
            prev=temp;
            temp=next;
            next=next->next;
        }
        temp->next=prev;
        return temp;
    }
    void reorderList(ListNode* head) {
        if(head->next==nullptr) return;
        if(head->next->next==nullptr) return;
        ListNode* mid=head,*end = head,*start=head,*list2,*temp1;
        while(end->next!=nullptr && end->next->next!=nullptr){
            mid=mid->next;
            end=end->next->next;
        }
        list2=reverse(mid->next);
        mid->next=nullptr;            
        while(list2->next){
            temp1=list2->next;
            list2->next=start->next;
            start->next=list2;
            start=start->next->next;
            list2=temp1;
        }
        list2->next=start->next;
        start->next=list2;

    }
};
