class Solution {
public:
    vector<string> phone;
    vector<string> ret;
    string s ="";
    vector<string> letterCombinations(string digits) { 
        
        phone = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(0,digits);

        return ret;
    }
    void helper(int start,string digits){
                
        if(s.size() == digits.size()){
            if (s.size() != 0)  ret.push_back(s);
            return;
        }
        
        int key = digits[start]-'2';
        for(int i = 0;i<phone[key].size();i++){
            s += phone[key][i];
                helper(start+1,digits);
                s.pop_back();
        }
    }
};
