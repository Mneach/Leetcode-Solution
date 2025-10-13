/*

How to solve the problem

# Using Stack
1. initialize variables
   - stack<char> st
   - result = ""
2. loop from the first idnex of string s until last index of string s
   - if st.empty()
     - push s[i] into the stack
   - if st.top() is a non digit and s[i] is a digit
     - st.pop
   - else
     - push s[i] into the stack
3. loop for every ata in the stack
   - result += st.top()
   - st.pop()
4. reverse the result string
5. return result

Time Complexity : O(N + M)
N -> length of string s
M -> size of stack

Memory Compleixty : O(M)
M -> size of stack

*/

class Solution {
    bool isDigit(char x) {
        return x >= '0' && x <= '9';
    }
public:
    string clearDigits(string s) {
        string result = "";
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else if (isDigit(st.top()) == false && isDigit(s[i]) == true) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        while (st.size() > 0) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};