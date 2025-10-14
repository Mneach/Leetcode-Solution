
/*

How to solve the problem

# Using Stack
1. initialize varaibles
   - stack<pair<char,int>> st
     - first -> represent the character
     - second -> represent total adjecent character
   - string result = "";
2. loop for every character in string s
   - if stack.empty()
     - push {s[i], 1} to the stack
   - else if (stack.top().first != s[i])
     - push {s[i], 1} to the stack
   - else 
     - [character, total] = st.top()
     - st.pop()
     - if (total + 1 < k)
       - st.push({character, total + 1})
3. Loop for every data in stack
   - [character, total] = st.top()
   - while total > 0
     - result += character
     - total -= 1
   - st.pop();
4. reverse result string
5. return the result

Time Complexity : O(N + N + M + N) = O(3N + M) = O(N)
N -> length of string s
M -> total data in stack

first N -> because we need to loop from first index of s until last index
second N -> because for every index in string s, we need to do these operations (push, pop, peek) from stack
third M -> to construct the answer
fourth N -> reverse the string

Memory Complexity : O(M)
M -> total data in stack

*/


class Solution {
public:
    string removeDuplicates(string s, int k) {
        // first = character
        // second = total adjecent character
        stack<pair<char,int>> st;
        string result = "";

        for (int i = 0; i < s.length(); i++) {
             if (st.empty()) {
                st.push({s[i], 1});
             } else {
                auto [character, total] = st.top();

                if (character == s[i]) {
                    st.pop();
                    if (total + 1 < k) {
                        st.push({character, total + 1});
                    }
                } else {
                    st.push({s[i], 1});
                }
             }
        }

        while (st.size() > 0) {
            auto [character, total] = st.top();
            st.pop();

            while (total > 0) {
                result += character;
                total--;
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};