/*

# Using stack
1. initialize variables
   - stack<char> st
2. loop from first index of s until last index of s
   - if (stack.empty() || s[i] == open bracket)
     - push s[i] into the stack
   - else
     - if (st.top() == open bracket && s[i] == close brakcet)
       - st.pop()
    - else
       - push s[i] into the stack
3. return stack.size()

Time Complexity : O(N)
N -> length of string s

Memory Complexity : O(M)
M -> size of stack

*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (st.empty() || s[i] == '(' ) {
                st.push(s[i]);
            } else {
                if (st.top() == '(' && s[i] == ')') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        } 

        return st.size();
    }
};