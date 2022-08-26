//Using unordered map and calculate the sum of two vectors at once

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int length = nums1.size();
        unordered_map<int,int> m1;
        int count = 0;
        
        for(int i =0;i<length;i++){
            for(int j = 0;j<length;j++)
                m1[nums1[i]+nums2[j]]++;
        }
        
        for(int i =0;i<length;i++){
            for(int j = 0;j<length;j++){
                int rem = 0-nums3[i]-nums4[j];
                if (m1.find(rem)!=m1.end())
                    count+=m1[rem];
            }                
        }
        return count;
            
    }
};
