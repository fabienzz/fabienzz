class Solution {
public:
    int strStr(string haystack, string needle) {
        int length = needle.size();
        if (length == 0)
            return -1;
        int arr[length];
        getNext(arr,needle);
        int j =0;
        for(int i = 0;i<haystack.size();i++){
            while(j>0&&haystack[i]!=needle[j])
                j = arr[j-1];
            if (haystack[i] == needle[j]){
                j++;
            }
            if (j == length)
                return i-length+1;
            
        }
    return -1;       
    }
    
    void getNext(int* arr,string &s){
        int j =0;
        arr[0] = j;
        for(int i=1;i<s.size();i++){
            while(j>0&&s[i]!=s[j])
                j = arr[j-1];
            if (s[i] == s[j]){
                j++;
            }
            arr[i] = j;
        }
    }
};
