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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low =0,high = nums.size()-1;
        TreeNode* root = helper(nums,low,high);
        return root;
    }
    
    TreeNode* helper(vector<int>& nums,int low, int high){
        if (high < low)    return NULL;
        int mid = (low+high)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums,low,mid-1);
        node->right = helper(nums,mid+1,high);
        
        return node;
        
        
    }
};
