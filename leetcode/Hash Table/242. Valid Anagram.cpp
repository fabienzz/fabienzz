1. Using Unordered_map
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(int i =0;i<s.size();i++){
            if(m.find(s[i])!=m.end())
                m[s[i]]++;
            else
                m.insert(make_pair(s[i],1));
        }
        
        for(int i = 0;i<t.size();i++){
            if(m.find(t[i])==m.end())
                return false;
            else{
                if (m[t[i]] == 1 )
                    m.erase(t[i]);
                else
                    m[t[i]]--;
            }
        }
        return m.empty();
    }
};

2.Using Array
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        for(int i = 0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        
        for(int i = 0;i<t.size();i++){
            arr[t[i]-'a']--;
        }
        
        for(int i =0;i<26;i++){
            if (arr[i])
                return false;
        }
        return true;
    }
};
