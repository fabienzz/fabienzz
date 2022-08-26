class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int arr[1002]={0};
        unordered_set<int>s;
        for(int i = 0;i<nums1.size();i++)
            arr[nums1[i]]=1;
        for(int i = 0;i<nums2.size();i++){
            if (arr[nums2[i]] == 1)
                s.insert(nums2[i]);
        }
        return vector<int>(s.begin(),s.end());
    }
};
