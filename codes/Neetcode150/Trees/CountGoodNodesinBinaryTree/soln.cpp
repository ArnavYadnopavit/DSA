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
    int goodNodes(TreeNode* root) {
        return dfs(root, -101);
    }
private:
int dfs(TreeNode* root, int max_till_now){
    if(!root) return 0;
    if(root->val>=max_till_now) {
        return 1+dfs(root->left,root->val)+dfs(root->right,root->val);
    
    }
    return dfs(root->left,max_till_now)+dfs(root->right,max_till_now);
}
};
