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
    vector<int> findMode(TreeNode* root) {
        if (!root->left&&!root->right)  return vector<int>(1,root->val);
        unordered_map<int,int> m1;
        vector<int> ret;
        helper(root,m1);
        int ma = 0;
        for(unordered_map<int,int>:: iterator it = m1.begin();it != m1.end();it++){
            if (it->second>ma)  ma = it->second;
        }
        for(unordered_map<int,int>:: iterator it = m1.begin();it != m1.end();it++){
            if (it->second == ma)  ret.push_back(it->first);
        }
        return ret;
        
    }
    void helper(TreeNode* root,unordered_map<int,int>& m1){
        if (root == nullptr)    return;
        m1[root->val]++;
        helper(root->left,m1);
        helper(root->right,m1);
    }
};

/--------------------------------------------------------------------------------------
    class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int maxCount = 0; // 最大频率
        int count = 0; // 统计频率
        vector<int> result;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top();
                st.pop();                       // 中
                if (pre == NULL) { // 第一个节点
                    count = 1;
                } else if (pre->val == cur->val) { // 与前一个节点数值相同
                    count++;
                } else { // 与前一个节点数值不同
                    count = 1;
                }
                if (count == maxCount) { // 如果和最大值相同，放进result中
                    result.push_back(cur->val);
                }

                if (count > maxCount) { // 如果计数大于最大值频率
                    maxCount = count;   // 更新最大频率
                    result.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
                    result.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;               // 右
            }
        }
        return result;
    }
};
