class Solution {
public:
    vector<vector<int>> ret;
    vector<int> v;
    vector<vector<int>> subsets(vector<int>& nums) {

        helper(0,nums);
        return ret;
    }
    void helper(int start, vector<int>& nums){

        if (start<nums.size()+1){
            ret.push_back(v);
        }
        
        for(int i =start;i<nums.size();i++){
            v.push_back(nums[i]);
            helper(i+1,nums);
            v.pop_back();
        }
    }
};
