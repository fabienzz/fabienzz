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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0)   return NULL;
        
        int mval = nums[0];
        int mind=0;
        for(int ind = 0;ind<nums.size();ind++){
            if(nums[ind]>mval)  {
                mval = nums[ind];
                mind = ind;
            }
        }
        
        TreeNode* root =  new TreeNode(mval);
        if (nums.size()==1)     return root;
        
        vector<int> left(nums.begin(),nums.begin()+mind);
        vector<int> right(nums.begin()+mind+1,nums.end());
        
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        
        return root;
    }
};
