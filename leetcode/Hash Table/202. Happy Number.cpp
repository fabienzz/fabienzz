class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>m;
        int temp = happy(n);
        while(temp!=1){
            if(m.find(temp)==m.end())
                m[temp]++;
            else{
                return false;
            }
            temp = happy(temp);
        }
        return true;
    }
    
    int happy(int n){
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        int temp = happy(n);
        while(temp!=1){
            if(s.find(temp)==s.end())
                s.insert(temp);
            else{
                return false;
            }
            temp = happy(temp);
        }
        return true;
    }
    
    int happy(int n){
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }
};
