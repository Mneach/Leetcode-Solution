/*

How to solve the problem

# Main Idea 
1. Using two stack to maintain the data
   - first stack to maintain the data
   - second stack to get the minimum data based on the user input

# Using Two Stack
1. initialize variables
   - stack<int> st
   - stacK<int> minStack
2. push functions
   - push value into the stack
   - if minStack == empty
     - push value into the stack
   - else value <= minStack.top()
     - push value into the minStack
3. pop functions
   - if st.top() == minStack.top()
     - pop from the minstack
   - pop from the stack
4. top functions
   - return st.top()
5. getMin functions
   - return minStack.top()

Time Complexity : O(1)

Memory Compelxity : O(N + M)
N -> size of stack
M -> size of minStack

*/

class MinStack {
private:
    stack<int> st;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if (minStack.empty()) {
            minStack.push(val);
        } else if (val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (minStack.top() == st.top()) {
            minStack.pop();
        }

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
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