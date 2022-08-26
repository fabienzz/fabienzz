class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ret;
        for(int i =0;i<nums.size();i++)
            m[nums[i]] = i;
        
        for(int i =0;i<nums.size();i++){
            int rem = target-nums[i];
            if(m.find(rem)!=m.end()&&m[rem]!=i){
                ret.push_back(m[rem]);
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
};
