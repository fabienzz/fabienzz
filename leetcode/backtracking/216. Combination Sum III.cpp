class Solution {
public:
    vector<vector<int>> ret;
    vector<int>v;
    vector<vector<int>> combinationSum3(int k, int n) {
        
        helper(1,k,n);
        return ret;
    }
    int sum1(vector<int> v1){
        int tmp = 0;
        for(int i =0;i<v1.size();i++)
            tmp += v1[i];
        return tmp;
    }
    void helper(int start,int k,int n){
        if (v.size() == k&& sum1(v) == n){
            ret.push_back(v);
            return;
        }
        
        int top = 10>n-k+1?n-k+2:10;
        
        for(int i = start;i < top;i++){
            v.push_back(i);
            helper(i+1,k,n);
            v.pop_back();
        }
    }
};
