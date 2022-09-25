class Solution {
public:
    set<vector<int>> ret;
    vector<int> v;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target);
        return vector<vector<int>>(ret.begin(),ret.end());
    }
    
    void helper(int start,vector<int>& candidates, int target){
        if (target < 0)
            return;
        
        if (target == 0){
            ret.insert(v);
            return;
        }
        
        for(int i = start;i < candidates.size();i++){
            
            if (i>start && candidates[i] == candidates[i-1])
                continue;
            v.push_back(candidates[i]);
            helper(i+1,candidates,target-candidates[i]);
            v.pop_back();
        }
    }
};
