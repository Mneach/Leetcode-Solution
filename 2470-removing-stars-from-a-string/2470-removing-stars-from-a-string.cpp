/*

How to solve the problem

# Using stack
1. initialize variables
   - string result = ""
   - stack<char> st
2. loop from the first index of string s until last index of string s
   - if st.size() > 0 && s[i] == '*'
     - st.pop()
   - if s[i] != '*'
     - st.push(s[i])
3. whilt st.size() > 0
   - result = st.top()
   - st.pop()
4. reverse the result string
5. return result

Time Complexity : O(N + M + M / 2)
N -> length of string s
M -> total characters in the stack

Memory Complexity : O(M)
M -> total characters in the stack

*/

class Solution {
public:
    string removeStars(string s) {
        string result = "";
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (st.size() > 0 && s[i] == '*') {
                st.pop();
            } else if (s[i] != '*') {
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