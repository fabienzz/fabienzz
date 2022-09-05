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
    vector<int> findMode(TreeNode* root) {
        if (!root->left&&!root->right)  return vector<int>(1,root->val);
        unordered_map<int,int> m1;
        vector<int> ret;
        helper(root,m1);
        int ma = 0;
        for(unordered_map<int,int>:: iterator it = m1.begin();it != m1.end();it++){
            if (it->second>ma)  ma = it->second;
        }
        for(unordered_map<int,int>:: iterator it = m1.begin();it != m1.end();it++){
            if (it->second == ma)  ret.push_back(it->first);
        }
        return ret;
        
    }
    void helper(TreeNode* root,unordered_map<int,int>& m1){
        if (root == nullptr)    return;
        m1[root->val]++;
        helper(root->left,m1);
        helper(root->right,m1);
    }
};
