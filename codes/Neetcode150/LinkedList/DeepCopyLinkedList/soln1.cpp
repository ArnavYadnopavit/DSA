/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <iostream>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map <Node*,Node*> Connections;
        if(!head) return nullptr;
        Node* rethead=new Node(head->val);
        Connections[head] = rethead;
        Node* temp=head,*tempret=rethead,*prev=temp;
        while(temp){
            if(!temp->next){
                tempret->next=nullptr;
            }
            else if(Connections.find(temp->next)==Connections.end()){
                tempret->next=new Node(temp->next->val);
                Connections[temp->next]=tempret->next;
            }
            else{
                tempret->next=Connections[temp->next];
            }
            if(!temp->random){
                tempret->random=nullptr;           
            }
            else if(Connections.find(temp->random)==Connections.end()){
                tempret->random=new Node(temp->random->val);
                Connections[temp->random]=tempret->random;
            }
            else{
                tempret->random=Connections[temp->random];
            }
            tempret=tempret->next;
            temp=temp->next;
        }
        return rethead;
        
    }
};
