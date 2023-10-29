class MinStack {
public:
    
    stack<int> stack1;
    stack<int> stack2;
    
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(stack2.size() == 0) stack2.push(val);
        else if(stack2.top() >= val) stack2.push(val);
        
        stack1.push(val);
    }
    
    void pop() {
        
        if(stack2.top() == stack1.top()) stack2.pop();
        stack1.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */