class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 0;i<s.size()/2;i++){
            int length = i+1;
            bool ret = true;
            int start = 0;
            for(int j = i+1;j<s.size()&&ret;j++){
                if (s[j]!=s[start])
                    ret = false;
                start = (start+1)%length;
            }
            if (ret&&start==0)
                return true;
        }
        return false;
    }
};


// Time complexity O(n^2)
// Space complexity O(1)
