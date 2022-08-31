class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> ret;
        for(int i = 0;i<s.size();i++){
            if(ret.empty())
                ret.push(s[i]);
            else{
                if (ret.top() == s[i])
                    ret.pop();
                else
                    ret.push(s[i]);      
            }
        }
        
        string res(ret.size(),'a');
        for(int i =ret.size()-1;i>=0;i--){
            res[i] = ret.top();
            ret.pop();
        
        }
        return res;
    }
};
