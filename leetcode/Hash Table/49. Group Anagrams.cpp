class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int length = strs.size();
        vector<vector<string>> ret;
        unordered_map <string,vector<string>> m;
        for(int i = 0;i<length;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]);
        }
        
        for(unordered_map<string,vector<string>>::iterator it = m.begin();it!=m.end();it++){
            ret.push_back(it->second);
        }
        return ret;
        }
 };
