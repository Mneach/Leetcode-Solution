/*

How to solve the problem : 

# Using one queue
1. push function
   - push x into the queue
   - loop from 0 until queue.size() - 1
   - get queue front, and push that again into the queue
2. pop
   - pop front from the queue
3. top
   - return queue.front()
4. empty
   - return queue.empty()

*/

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);

        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int value = q.front(); 
        q.pop();
        return value;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
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