// 找到删除的节点
// 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
// 第三种情况：删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
// 第四种情况：删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
// 第五种情况：左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）放到删除节点的右子树的最左面节点的左孩子上，返回删除节点右孩子为新的根节点。

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)  return root;
        if(root->val == key){
            if(!root->left&&!root->right){
                delete root;
                return NULL;
            }   
            else if (!root->right){
                TreeNode* node = root->left;
                delete root;
                return node;
            }   
            else if (!root->left){
                TreeNode* node = root->right;
                delete root;
                return node;
            } 
            else{
                TreeNode* cur = root->right;
                while(cur->left)
                    cur = cur->left;
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        
        if (root->val > key)    root->left = deleteNode(root->left,key);
        if (root->val <key)     root->right = deleteNode(root->right,key);
       return root;
    }
};
