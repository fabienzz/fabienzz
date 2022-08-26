class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int p_size = p.size();
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        vector<int> ret;
        
        for(int i = 0; i< p_size;i++)
            m1[p[i]]++;
        
        for (int i = 0;i< p_size-1;i++)
            m2[s[i]]++;
        
        for (int i = p_size-1;i< s.size();i++){
            
            m2[s[i]]++;
            if (m1 == m2)
                ret.push_back(i-p_size+1);
            
            if (m2[s[i-p_size+1]] == 1)
                m2.erase(s[i-p_size+1]);
            else
                m2[s[i-p_size+1]]--;           
        }
        return ret;   
    }
};
