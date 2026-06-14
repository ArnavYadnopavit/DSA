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
    int kthSmallest(TreeNode* root, int k) {
        deque <TreeNode*> dq;
        inorder(root,dq,k);
        return dq.back()->val;
    }
private:
    void inorder(TreeNode* root, deque <TreeNode*> &dq, int k){
        if(dq.size()==k) return;
        if(!root) return;
        inorder(root->left,dq,k);
        if(dq.size()==k) return;
        dq.push_back(root);
        
        inorder(root->right,dq,k);
    }
};
