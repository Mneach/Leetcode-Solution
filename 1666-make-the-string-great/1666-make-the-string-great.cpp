/*

How to solve the problem

# Using Stack
1. initialize variables
   - stack<char> st
   - result = ""
2. loop for every index from 0 until s.length() - 1
   - if s[i] is uppercase letter
     - x = change s[i] to lower case letter
     - if stack.top() == x, then remove the data from stack (stack.pop())
     - else push s[i] into the stack
   - else 
     - x = change s[i] to the upper case
     - if stack.top() == x, then remove the data ffrom stack (stack.pop())
     - else push s[i] into the stack
3. loop for every data in the stack, push the data into the result string
4. return the result

Time Complexity : O(N + M + M) -> O(N)
N -> size of string
M -> size of stacks

Memory Complexity : O(M)
M -> size of stacks

*/


class Solution {
private:
    bool isUpperCaseLetter(char x) {
        return x >= 'A' && x <= 'Z';
    }    
public:
    string makeGood(string s) {
        string result = "";
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (isUpperCaseLetter(s[i])) {
                
                if (st.size() > 0 && st.top() == (s[i] - 'A') + 'a') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            } else {
                if (st.size() > 0 && st.top() == (s[i] - 'a') + 'A') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
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