class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string tmp = "";
        for(int i = 0 ;i<s.size();i++){
            if (s[i] == ' ' && tmp !=""){
                v.push_back(tmp);
                tmp = "";
            }
            else if (s[i] !=' '){
                tmp += s[i];
            }
            if (i == s.size()-1 && tmp !="")
                v.push_back(tmp);  
        }
        
        tmp = "";
        for (int i =v.size()-1;i>= 0;i--){
            tmp += v[i];
            if (i!=0) tmp += " ";
        }
        return tmp;
    }
};
