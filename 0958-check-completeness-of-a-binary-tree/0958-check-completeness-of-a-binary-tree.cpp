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
class Solution {
public:
    int calcTotalNodes(TreeNode* root) {
        if (root == NULL) return 0;

        return 1 + calcTotalNodes(root->left) + calcTotalNodes(root->right);
    }
    bool isCompleteTree(TreeNode* root) {
        int total = calcTotalNodes(root);
        int curr = 0;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            if (node == NULL) return total == curr;
            q.pop();
            curr++;
            q.push(node->left);
            q.push(node->right);
        }
        return 0;
    }
};