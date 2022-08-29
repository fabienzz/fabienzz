class Solution {
public:
    string reverseWords(string s) {

        
        int slow = 0;
        
        for(int i = 0;i<s.size();++i){
            //跳过所有空格 skipping all space
            if (s[i]!=' '){
                //如果是第一个单词，不需要在前面加空格，否则加上 Manually add a single space before words (except for the 1st word)
                if (slow!=0){
                    s[slow] = ' ';
                    slow++;
                }
                
                //逐个复制字母直到单词结束 copying the word char by char until it reaches the end of this word
                while(i<s.size()&&s[i]!=' '){
                    s[slow] = s[i];
                    i++;
                    slow++;
                }
            }
        }
        
        s.resize(slow);
        reverse(s.begin(),s.end());
        
        int start = 0;
        for(int i = 0;i<=s.size();i++){
            if (s[i]==' '||i ==s.size()){
                reverse(s.begin()+start,s.begin()+i);
                start = i+1;
            }
        }
        
        return s;
    }
};
