/*

How to solve the problem

# Using stack
1. initialize varaibles
   - stack<string> st
   - word = ""
2. loop from the first index of string s until last index of string s
   - if s[i] == open bracket
     - if word != ""
       - push word into the stack
       - word = ""
     - push open bracket to stack
   - else if s[i] == close bracket
     - push word into the stack
     - word = "";
     - while stack.size() > 1
       - get first data and second data from stack
       - if second data == open bracket
         - reverse the first data
         - push first data into the stack
         - break
       - else
         - combine second data + first data
         - push that data into the stack
   - else 
     - word += s[i]
3. if word != ""
   - push word into the stack
4. while stack.size() > 1
   - if stack.size() == 1
     - return stack.top()
   - else
     - get first data and second data from stack
     - if second data == open bracket
        - reverse the first data
        - push first data into the stack
        - break
     - else
        - combine second data + first data
        - push that data into the stack
4. return stack.top()

Time Complexity : O(N + (M * K / 2))
N -> length of string s
M -> size of the stack
K -> maximum word length in string s

Memory Complexity : O(M)
M -> size of the stack

*/

class Solution {
public:
    string reverseParentheses(string s) {
        string word = "";
        stack<string> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                if (word != "") {
                    st.push(word);
                    word = "";
                }

                st.push("(");
            } else if (s[i] == ')') {
                st.push(word);
                word = "";

                while (st.size() > 1) {
                    string firstData = st.top(); st.pop();
                    string secondData = st.top(); st.pop();

                    if (secondData == "(") {
                        reverse(firstData.begin(), firstData.end());
                        st.push(firstData);
                        break;
                    } else {
                        st.push(secondData + firstData);
                    }
                }
            } else {
                word += s[i];
            }
        }

        if (word != "") {
            st.push(word);
        }

        while (st.size() > 0) {

            if (st.size() == 1) {
                return st.top();
            }

            string firstData = st.top(); st.pop();
            string secondData = st.top(); st.pop();

            if (secondData == "(") {
                reverse(firstData.begin(), firstData.end());
                st.push(firstData);
                break;
            } else {
                st.push(secondData + firstData);
            }
        }

        return st.top();
    }
};