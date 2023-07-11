/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    map<TreeNode*, TreeNode*> m;
    vector<int> ans;
    void makeParent(TreeNode* root, TreeNode* parent){
        if(root==NULL)return;
        m[root]=parent;
        makeParent(root->left,root);
        makeParent(root->right,root);
    }

    void dfs(TreeNode* root,int k, TreeNode* prev){
        if(root==NULL)return ;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        if(root->left!=prev)dfs(root->left,k-1,root);
        if(root->right!=prev)dfs(root->right,k-1,root);
        if(m[root]!=prev)dfs(m[root],k-1,root);
    }


public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeParent(root,NULL);
        dfs(target,k,NULL);
        return ans;
;    }
};