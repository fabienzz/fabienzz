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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == nullptr)
            return ret;
        string cur;
        cur+= to_string(root->val);
        helper(root,cur,ret);
        return ret;
            
    }
    
    void helper(TreeNode* node,string cur,vector<string>& ret){
        if (!node->left &&!node->right){
           ret.push_back(cur);
        } 
        if (node->left){
            helper(node->left,cur + "->"+to_string(node->left->val),ret);
        }
        if (node->right){
            helper(node->right,cur + "->"+ to_string(node->right->val),ret);
        }
    }
};
