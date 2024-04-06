class CustomStack {
public:
    
    int size;
    stack<int> st;
    stack<int> bucket;
    
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(st.size() < size){
            st.push(x);
        }
    }
    
    int pop() {
        if(st.empty() == false){
            int top = st.top();
            st.pop();
            return top;
        }else{
            return -1;
        }
    }
    
    void increment(int k, int val) {
        int current = 1;
        int stackSize = st.size();
        while(st.empty() == false){ 
            if(current > stackSize - k) bucket.push(st.top() + val);
            else bucket.push(st.top());
            
            current++;
            st.pop();
        }
        
        while(bucket.empty() == false){
            st.push(bucket.top());
            bucket.pop();
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */