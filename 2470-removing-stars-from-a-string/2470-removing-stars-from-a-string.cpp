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

# Can we improve the memory compleixty ? 
1. if we want to improve the memory complexity, that means we cannot use stack to solve the problem. What iam thinking is i think we can use two pointer technique to solve the problem

# Using two pointer technique
1. initialize variables
   - left = 0
   - right = 0
   - result = ""
2. while right < s.length()
   - if (s[right] != '*')
     - change s[l] to s[r], because the s[r] must be the valid character to take
     - increase the left pointer
   - else 
     - decrease the left pointer, because we dont wakt to take the s[l] character, since there is an asterix 
3. loop from 0 until L to get the result
4. return the result

Time Complexity : O(N + M)
N -> length of string S
M -> total result characters

Memory Complexity : O(1)

*/

class Solution {
public:
    string removeStars(string s) {
        string result = "";
        int left = 0;
        int right = 0;

        while (right < s.length()) {
            if (s[right] != '*') {
                s[left] = s[right];
                left++;
            } else {
                left--;
            }

            right++;
        }

        for (int i = 0; i < left; i++) {
            result += s[i];
        }

        return result;
    }
};