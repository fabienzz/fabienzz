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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        int depth =0;
        helper(root,ret,depth);
        reverse(ret.begin(),ret.end());
        return  ret;
    }
    void helper(TreeNode* node,vector<vector<int>>& ret,int depth){
        
        if (node == nullptr)    return;
        if (depth == ret.size())    ret.push_back(vector<int>());
        helper(node->left,ret,depth+1);
        helper(node->right,ret,depth+1);
        ret[depth].push_back(node->val);
    }
};
