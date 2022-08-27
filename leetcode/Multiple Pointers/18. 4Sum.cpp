class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int left = -1;
        int right = -1;
        sort(nums.begin(),nums.end());
        
        for(int i =0;i<nums.size();i++){
            
            if(nums[i] > target && (nums[i] >=0 || target >= 0))//剪枝
                break;
            
            if (i>0&&nums[i] == nums[i-1])//去重
                continue;
            
            for(int j =i+1;j<nums.size();j++){
                
                if (nums[j] + nums[i] > target && nums[j] + nums[i] >= 0)//剪枝
                    break;
                
                if (j>i+1&&nums[j] == nums[j-1])//去重
                    continue;
                
 
                
                left = j+1;
                right = nums.size()-1;
                
                while(right>left){
                    long sum = nums[i]+ (long)nums[j]+ nums[left]+ nums[right];
                    if (sum>target) right--;
                    else if (sum<target) left++;
                    else{
                        ret.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while(right>left&&nums[right] == nums[right-1]) right--;
                        while(right>left&&nums[left] == nums[left+1]) left++;
                        right--;
                        left++;
                    }
                }          
            }
        }
        
        return ret;
    }
};
