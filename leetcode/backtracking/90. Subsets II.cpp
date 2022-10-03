class Solution {
public:
    vector<vector<int>> ret;
    vector<int> v;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // otherwise same elements will not show up sequencially, then line 18 will not make sense, 
        helper(0,nums);
        return ret;
    }
    
    void helper(int start, vector<int>& nums){

        if (start<nums.size()+1){
            ret.push_back(v);
        }
        
        for(int i =start;i<nums.size();i++){
            if (i && nums[i] == nums[i-1]&&start!=i)  continue;
            v.push_back(nums[i]);
            helper(i+1,nums);
            v.pop_back();
        }
    }
};
