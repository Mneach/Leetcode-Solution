class CustomStack {
public:
    
    vector<int> stack, bucketIncrement;
    int n;
    
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(stack.size() == n) return;
        
        stack.push_back(x);
        bucketIncrement.push_back(0);
    }
    
    int pop() {
        int stackSize = stack.size() - 1;
        
        if(stackSize < 0) {
            return -1;
        }else if(stackSize > 0){
            bucketIncrement[stackSize - 1] += bucketIncrement[stackSize];
        }
        int top = stack[stackSize] + bucketIncrement[stackSize];
        stack.pop_back();
        bucketIncrement.pop_back();
        
        return top;
    }
    
    void increment(int k, int val) {
        int stackSize = stack.size();

        int minimum = min(k, stackSize) - 1;
        
        if(minimum >= 0) bucketIncrement[minimum] += val;
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */