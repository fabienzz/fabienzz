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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)  return new TreeNode(val);
        TreeNode* head = root;
        TreeNode* pre = NULL;
        while(root){
            pre = root;
            if (root->val > val)  root = root->left;
            else root = root->right;
        }
        
        TreeNode* node = new TreeNode(val);
        if (pre->val > val) pre->left = node;
        else pre->right = node;
        return head;
        
    }
};
