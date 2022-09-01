/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        queue<Node*> q1;
        if (root != nullptr)    q1.push(root);
        while(!q1.empty()){
            int size = q1.size();
            vector<int> v;
            for(int i=0;i<size;i++){
                Node* node = q1.front();
                if (!node->children.empty()){
                    int cSize = node->children.size();
                    for(int j =0;j<cSize;j++){
                        if (node->children[j] != nullptr)   q1.push(node->children[j]);
                    }
                }
                v.push_back(node->val);
                q1.pop();
            }
            ret.push_back(v);
        }
        
        return ret;
    }
};
