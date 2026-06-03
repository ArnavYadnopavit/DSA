/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map <Node*,Node*> CloneMapping;
        Node * ret = dfs(node,CloneMapping); 
        return ret;
    }
private:
    Node* dfs(Node*& old, unordered_map <Node*,Node*>& hash){
        if(!old) return nullptr;
        deque<Node*> dq;
        Node* ret = new Node(old->val),*temp;
        dq.push_front(old);
        hash[old]=ret;
        while(dq.size()>0){
            temp = dq.front();
            dq.pop_front();
            Node* clonedtemp = hash[temp];
            for(auto node: temp->neighbors){
                if (!node) continue;
                else if(hash.find(node)==hash.end()){
                    Node* tempnew = new Node(node->val);
                    hash[node] = tempnew;
                    clonedtemp->neighbors.push_back(tempnew);
                    dq.push_front(node);
                }
                else{
                    clonedtemp->neighbors.push_back(hash[node]);
                }
            }
        }
        return ret;
    }
};
