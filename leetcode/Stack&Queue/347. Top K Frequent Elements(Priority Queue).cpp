class myCompare{
    public:
        bool operator()(pair<int,int> p1,pair<int,int> p2){
            return p1.second>p2.second;
        }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ret(k,0);
        for(int i =0;i<nums.size();i++)
            m[nums[i]]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>,myCompare> pq;
        for(unordered_map<int,int>::iterator it=m.begin();it != m.end();it++){
            pq.push(*it);
            if(pq.size()>k)
                pq.pop();
        }
        for(int i =k-1;i>=0;i--){
            ret[i] = pq.top().first;
            pq.pop();
        }
        return ret;
    }
};
