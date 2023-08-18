class MinStack {
public:
    
    stack<int> st;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> temp;
        
        int minimum = INT_MAX;
        while(st.empty() == false){
            temp.push(st.top());
            minimum = min(minimum, temp.top());
            st.pop();
        }
        
        while(temp.empty() == false){
            st.push(temp.top());
            temp.pop();
        }
        
        return minimum;
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