class MyStack {
private:
    deque<int> dq;
public:
    MyStack() {
        
    }
    
    void push(int x) {
       dq.push_back(x); 
    }
    
    int pop() {
        int result = top();
        dq.pop_back();
        return result;
    }
    
    int top() {
       return dq.back(); 
    }
    
    bool empty() {
        return dq.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */