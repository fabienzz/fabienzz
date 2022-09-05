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
    bool isValidBST(TreeNode* root) {
        vector<int> values;
        helper(root,values);
        for(int i=1;i<values.size();i++){
            if(values[i]<=values[i-1])  return false;
        }
        return true;
    }
    void helper(TreeNode* root,vector<int>& values){
        if (root == NULL)   return;
        helper(root->left,values);
        values.push_back(root->val);
        helper(root->right,values);
        
        
    }
};
