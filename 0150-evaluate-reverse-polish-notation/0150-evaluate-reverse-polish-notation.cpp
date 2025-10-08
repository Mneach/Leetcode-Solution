/*

How to solve the problem

# Using stack
1. initialize variables
   - stack<int> st
2. loop from the first index of tokens until last index of tokens
   - if tokens[i] is a number
     - then put a number into the stack
   - otherwise
     - get 2 numbers from stack
     - first = stack.top()
     - stack.pop()
     - second = stack.top()
     - stack.pop()
     - result = second (operation) first
     - put the result into the stack
3. return stack.top()

Time Complexity : O(N * M)
N -> length of tokens
M -> maximum number digit

Memory Complexity : O(K)
K -> size of the stack 

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;        

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                st.push(second + first);
            } else if (tokens[i] == "-") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                st.push(second - first);
            } else if (tokens[i] == "*") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                st.push(second * first);
            } else if (tokens[i] == "/") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                st.push(second / first);
            } else {
                // put tokens[i] into the stack
                int number = stoi(tokens[i]);
                st.push(number);
            }
        }
        
        return st.top();
    }
};