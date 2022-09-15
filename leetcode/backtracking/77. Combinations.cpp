class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> v;
        helper(1,n,k,ret,v);
        return ret;
    }
    
    void helper(int start,int n,int k,vector<vector<int>> &ret,vector<int> v){
        if (v.size() == k){
            ret.push_back(v);
            return;
        }
            
        for(int i = start;i<=n-(k-v.size())+1;i++){ //剪枝操作，如果for循环选择的起始位置之后的元素个数 已经不足 我们需要的元素个数了，那么就没有必要搜索了。
            v.push_back(i);
            helper(i+1,n,k,ret,v);
            v.pop_back();
        }
            
            
    }
};
