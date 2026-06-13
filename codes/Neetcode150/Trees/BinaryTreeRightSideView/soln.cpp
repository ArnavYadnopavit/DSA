/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */ 
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    if(!root) return {};
        queue <TreeNode*> q;
        vector<int> ret;
        q.push(root);
        while(q.size()>0){
            int s = q.size();
            ret.push_back(q.front()->val);
            for(int i = 0;i<s;i++){
                TreeNode* t = q.front();
                if(t->right) q.push(t->right);
                if(t->left) q.push(t->left);
                q.pop();
            }
        }
        return ret;
    }
};