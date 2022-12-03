class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ret;
        for(int i =0;i<nums.size();i++) // map each value to its index
            m[nums[i]] = i;
        
        for(int i =0;i<nums.size();i++){
            int rem = target-nums[i];
            if(m.find(rem)!=m.end()&&m[rem]!=i){ // if the remainder is not current value (cant use the same element twice)
                ret.push_back(m[rem]);
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
};
