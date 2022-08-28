class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        int cur = 0;
        
        if(length < 2*k){
            reverse(s,0,min(length-1,k-1));
            return s;
        }
        
        while(length>0){
            int reminder = length - 2*k;
            if (reminder<k){
                reverse(s,cur,cur+k-1);
                cur += 2*k;
                reverse(s,cur,s.size()-1);
                break;
            }
            else if(reminder ==k || reminder>2*k){
                reverse(s,cur,cur+k-1);
                length = length-2*k;
                cur += 2*k;
            }
            else{
                reverse(s,cur,cur+k-1);
                cur+=2*k;
                reverse(s,cur,cur+k-1);
                break;
            }
        }
        return s;
    }
    void reverse(string &s,int left,int right){
        while (right>left){
            int tmp = s[left];
            s[left]=s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }

};
