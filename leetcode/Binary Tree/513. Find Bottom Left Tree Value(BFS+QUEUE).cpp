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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q1;
        int bl =0;
        if (root!=nullptr)  q1.push(root);
        while(!q1.empty()){
            int size = q1.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q1.front();
                q1.pop();
                
                if (node->left)     q1.push(node->left);
                
                if(node->right)     q1.push(node->right);
                
                if (!i) bl = node->val;
            }
        }
        return bl;
    }
};
