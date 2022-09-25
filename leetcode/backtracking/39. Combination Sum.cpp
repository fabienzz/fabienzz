class Solution {
public:
    vector<vector<int>> ret;
    vector<int>  v;
    unordered_map<int,vector<int>> m;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(0,candidates,target);
        return ret;
    }
    
    void helper(int start,vector<int>& candidates, int target){
        if (target <0)  return;
        
        if (target == 0){// push the result if the reminder becomes 0
            ret.push_back(v);
            return;
        }
        
        for(int i = start; i < candidates.size();i++){
            v.push_back(candidates[i]);
            helper(i,candidates,target-candidates[i]);
            v.pop_back();
        }
    }
};
