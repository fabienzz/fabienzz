class MyStack {
public:
    MyStack() {
    }
    
    void push(int x) {
        this->q.push(x);
        if (!q.empty()){
            for(int i = 0;i<q.size()-1;i++){
                int val = q.front();
                q.pop();
                q.push(val);
            }
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
    queue<int>q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
