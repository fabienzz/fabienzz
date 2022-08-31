class Mqueue{
    public:
        void push(int val){
            while(!dq.empty()&&dq.back()<val)
                dq.pop_back();
            dq.push_back(val);
        }
    
        void pop(int val){
            if (!dq.empty()&& dq.front() == val)
                dq.pop_front();
                
        }
        
        int front(){
            return dq.front();
        }
    
        deque<int> dq;
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Mqueue mq;
        vector<int> res;
        for(int i =0;i<k;i++)
            mq.push(nums[i]);
        res.push_back(mq.front());
        for(int i = 0;i<nums.size()-k;i++){
            mq.pop(nums[i]);
            mq.push(nums[i+k]);
            res.push_back(mq.front());
        }
        
        return res;
    }
};



