class MyQueue {
public:
    MyQueue() {
        s = new stack<int>;
        count = 0;
    }
    
    void push(int x) {
        if (count>0){
            stack<int> tmp;
            for(int i =0;i<count;i++){
                tmp.push(s->top());
                s->pop();
            }
            s->push(x);
            for(int i =0;i<count;i++){
                s->push(tmp.top());
                tmp.pop();
            }
        }
        else{
            s->push(x);
        }
        count++;
    }
    
    int pop() {
        if (count>0){
            int val = s->top();
            s->pop();
            count--;
            return val;
        }
        return -1;  
    }
    
    int peek() {
        return s->top();
    }
    
    bool empty() {
        return count == 0;
    }
    stack<int>* s = NULL;
    int count;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
