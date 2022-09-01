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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ret;
        queue<TreeNode*> q1;
        if (root != nullptr)    q1.push(root);
        int right;
        while(!q1.empty()){
            bool changed = false;
            int size = q1.size();
            for(int i=0; i<size;i++){
                
                TreeNode* node = q1.front();
                if (node != nullptr){
                    q1.push(node->left);
                    q1.push(node->right);
                    right = node->val;
                    changed = true;
                }
               q1.pop();
            }
            if (changed)    ret.push_back(right);
        }
        return ret;
    }
    
};  
