/*

How to solve the problem

# Using two stacks
1. initialize variables
   - stack<int> st
   - stack<int> bucket
1. push function
   - move all the current data from stack to bucket
   - push x into the stack
   - move back again all of the data from bucket to stack
2. pop function
   - value = st.top()
   - st.pop()
   - return value
3. peek function
   - st.top()
4. empty function
   - return st.empty()

*/

class MyQueue {
private:
    stack<int> st;
    stack<int> bucket;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while (st.size() > 0) {
            bucket.push(st.top());
            st.pop();
        }

        st.push(x);
        while (bucket.size() > 0) {
            st.push(bucket.top());
            bucket.pop();
        }
    }
    
    int pop() {
        int value = st.top();
        st.pop();

        return value;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */