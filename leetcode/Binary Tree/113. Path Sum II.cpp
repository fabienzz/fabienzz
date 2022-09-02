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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        
        recur(root,targetSum,path,paths);
        
        return paths;
    }
    void recur(TreeNode* root, int targetSum, vector<int> path, vector<vector<int>> &paths){
        if (root == NULL){
            return;
        }
        
        int reminder = targetSum - root->val;
        
        path.push_back(root->val);
        if (reminder == 0 && root->left == NULL && root->right == NULL){
            paths.push_back(path);
            return;
        }

        if (root->left)
            recur(root->left,reminder,path,paths);
        if (root->right)
            recur(root->right,reminder,path,paths);

    }
};
