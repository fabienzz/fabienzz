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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0 || inorder.size() ==0)   return NULL;
        
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        
        if (preorder.size() ==1)    return root;
        
        int delimiter = 0;
        for(;delimiter<inorder.size();delimiter++){
            if(inorder[delimiter]==rootVal)  break;
        }
        
        vector<int> inorderLeft(inorder.begin(),inorder.begin()+delimiter);
        vector<int> inorderRight(inorder.begin()+delimiter+1,inorder.end());
        
        vector<int> preorderLeft(preorder.begin()+1,preorder.begin()+1+inorderLeft.size());
        vector<int> preorderRight(preorder.begin()+inorderLeft.size()+1,preorder.end());
        
        root->left = buildTree(preorderLeft,inorderLeft);
        root->right = buildTree(preorderRight,inorderRight);
        
        return root;
    }
};
