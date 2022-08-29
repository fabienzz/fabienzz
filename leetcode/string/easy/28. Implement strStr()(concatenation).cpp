class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string n(s);
        n+=s;
        n.erase(n.begin());
        n.erase(n.end()-1);
        if (n.find(s)!=std::string::npos)
            return true;
        return false;
        
            
    }
};
