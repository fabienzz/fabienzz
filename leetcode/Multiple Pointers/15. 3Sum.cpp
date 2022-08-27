class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int left = -1;
        int right = -1;
        sort(nums.begin(),nums.end());
        
        for (int i = 0;i<nums.size();i++){
            left = i+1;
            right = nums.size()-1;
            
            if(nums[i]>0){
                break;
            }
            
            if(i>0 && nums[i]==nums[i-1]) continue;//去除重复起始元素
            
            while(right>left){
                int sum = nums[i]+nums[left]+nums[right];
                if (sum > 0){
                    right--;
                }
                
                else if (sum == 0){
                    
                    ret.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(right>left&&nums[right]==nums[right-1]) right--;//直到左边不是相同元素时候停住
                    while(right>left&&nums[left]==nums[left+1]) left++;
                    right--;
                    left++;
                }
                else
                    left++;
            }
        }
        
        return ret;
    }
};
