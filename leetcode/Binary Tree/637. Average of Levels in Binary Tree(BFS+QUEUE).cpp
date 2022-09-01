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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        queue<TreeNode*> q1;
        if (root != nullptr)    q1.push(root);

        while(!q1.empty()){
            int size = q1.size();
            long sum = 0;

            
            for(int i=0; i<size;i++){
                TreeNode* node = q1.front();

                if (node->left)     q1.push(node->left);
                if (node->right)    q1.push(node->right);
                sum += node->val;

                q1.pop();
            }
            ret.push_back((double)sum/size);
        }
        return ret;
    }

};
