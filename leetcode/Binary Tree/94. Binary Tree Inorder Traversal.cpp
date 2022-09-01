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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        helper(root,ret);
        return ret;
    }
    
    void helper(TreeNode* node, vector<int> &ret){
        if(node == NULL)
            return;
        helper(node->left,ret);
        ret.push_back(node->val);
        helper(node->right,ret);
        
    }
};
