class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ret;
        int length = words.size();
        if (length == 0 || length == 1)
            return ret;
        
        vector<int> ref(26,0);
        for(int i = 0;i<words[0].size();i++)
            ref[words[0][i]-'a']++;
        for (int i = 1;i<length;i++){
            
            vector<int> tmp(26,0);
            
            for(int j = 0;j<words[i].size();j++){
                tmp[words[i][j]-'a']++;
            }
            
            for(int j = 0;j<26;j++){
                ref[j] = min(ref[j],tmp[j]);
            }
        }
        for(int j = 0;j<26;j++){
            while (ref[j]--){
                char tmp = 'a'+j;
                string s(1,tmp);
                ret.push_back(s);
            }
                
        }
        return ret;
    }
};
