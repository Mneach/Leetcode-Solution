/*

How to solve the problem 

# Using stack
1. initialize variables
   - stack<char> stack
2. loop from first index of string s until last index of string s
   - if stack empty
     - push s[i] into the stack
   - else if stack.top() == 'A' && s[i] == 'B'
     - stack.pop()
   - else if stack.top() == 'C' && s[i] == 'D'
     - stack.pop()
   - else
     - push the s[i] into the stack
3. return stack.size()

Time Complexity : O(N)
N -> length of string s

Memory Complexity : O(M)
M -> size of stack


*/

class Solution {
public:
    int minLength(string s) {
        stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            if (stack.size() == 0) {
                stack.push(s[i]);
            } else if (stack.top() == 'A' && s[i] == 'B') {
                stack.pop();
            } else if (stack.top() == 'C' && s[i] == 'D') {
                stack.pop();
            } else {
                stack.push(s[i]);
            }
        }

        return stack.size();
    }
};