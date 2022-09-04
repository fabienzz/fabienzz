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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size()==0 || inorder.size()==0)    return NULL;
        
        int rootVal = postorder.back();
        TreeNode* root = new TreeNode(rootVal);
        
        if(postorder.size()==1)     return root;
        
        int delimiter=0;
        for(;delimiter<inorder.size();delimiter++){
            if (inorder[delimiter]==rootVal) break;
        }
        
        vector<int> inorderLeft(inorder.begin(),inorder.begin()+delimiter);
        vector<int> inorderRight(inorder.begin()+delimiter+1,inorder.end());
        
        vector<int> postorderLeft(postorder.begin(),postorder.begin()+inorderLeft.size());
        vector<int> postorderRight(postorder.begin()+inorderLeft.size(),postorder.end()-1);
        
        root->left = buildTree(inorderLeft,postorderLeft);
        root->right = buildTree(inorderRight,postorderRight);
        
        return root;
        
    }
};
