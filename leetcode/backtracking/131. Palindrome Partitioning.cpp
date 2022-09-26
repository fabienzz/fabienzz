class Solution {
public:
    vector<vector<string>> ret;
    vector<string> v;
    
    bool palindrome(string s){
        
        int size = s.size();
        int low = 0, top = size-1;
        while(low<size){
            if (s[low]!=s[top]) return false;
            low++;
            top--;
        }
        return true;
        
    }
    
    vector<vector<string>> partition(string s) {
        helper(0,s);
        return ret;
    }
    
    void helper(int start,string s){
        if (start >=s.size()){
            ret.push_back(v);
            return;
        }
        
        for(int i = start;i < s.size();i++){
            string tmp = s.substr(start,i-start+1);
            if (palindrome(tmp)){
                v.push_back(tmp);
            }
            else    continue;
            helper(i+1,s);
            v.pop_back();
        }
    }
};
