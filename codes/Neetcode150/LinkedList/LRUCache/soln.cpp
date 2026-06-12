#include <iostream>
#include <unordered_map>
using namespace std;
class ListNode{
public:
    int key,val;
    ListNode* prev;
    ListNode* next;
    ListNode(int k,int v) : key(k),val(v),prev(nullptr), next(nullptr){}
};

class LRUCache {
    ListNode* left;
    ListNode* right;
    unordered_map <int, ListNode*> cache;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new ListNode(0,0);
        right = new ListNode(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        auto it=cache.find(key);
        if(it==cache.end()) return -1;
        ListNode* temp = it->second;
        remove(temp);
        insert(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        ListNode* temp;
        if(cache.find(key)!=cache.end()){
            temp = cache[key];
            temp->val = value;
            remove(temp);
            insert(temp);
            return;
        }
        else if(cache.size()>=cap){
            ListNode* rem = right->prev;
            remove(rem);
            cache.erase(rem->key);
            delete rem;
            
        }
        temp = new ListNode(key,value);
        cache[key]=temp;
        insert(temp);
    }
private:
    void remove(ListNode* node){
        ListNode* prv = node->prev;
        ListNode* nxt = node->next;
        prv->next=nxt;
        nxt->prev=prv;
    }
    void insert(ListNode* node){
        ListNode* head = left->next;
        left->next = node;
        node->prev=left;
        node->next = head;
        head->prev = node;
    }
};
