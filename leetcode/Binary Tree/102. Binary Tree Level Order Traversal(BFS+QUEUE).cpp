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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q1;
        if (root!=NULL) q1.push(root);
        while(!q1.empty()){
            vector<int> v;
            int size = q1.size();
           for(int i=0;i<size;i++){
                
                TreeNode* node = q1.front();
                
                if (node!=NULL){
                    q1.push(node->left);
                    q1.push(node->right);
                    v.push_back(node->val);
                }
                
                q1.pop();
                
            }
            if(!v.empty())  ret.push_back(v);
        }
        
        return ret;
    }
   
};
