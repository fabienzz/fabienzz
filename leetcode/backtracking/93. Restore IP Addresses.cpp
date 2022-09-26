class Solution {
public:
    vector<string> ret;
    
    bool isValid(string s,int start,int end){
        if (start > end)    return false;
        
        if (s[start] == '0' && start != end)    return false;   // cannot begin with 0
    
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0')  // 遇到非数字字符不合法
                return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
    
    vector<string> restoreIpAddresses(string s) {
        if (s.size()<4 || s.size()>12)  return ret;
        helper(0,0,s);
        return ret;
    }
    
    void helper(int startIndex,int pointNum,string s){
    
        if (pointNum == 3){
            if (isValid(s, startIndex, s.size()-1)){
                ret.push_back(s);
                return;
            }
                
        }
    
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
                s.insert(s.begin() + i + 1 , '.');  // 在i的后面插入一个逗点
                pointNum++;
                helper( i + 2, pointNum,s);   // 插入逗点之后下一个子串的起始位置为i+2
                pointNum--;                         // 回溯
                s.erase(s.begin() + i + 1);         // 回溯删掉逗点
            } else break; // 不合法，直接结束本层循环
        }
    }
};
