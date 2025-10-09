/*

How to solve the problem

# Using stack
1. initialize variables
   - stack<char> st
2. loop from the first character from string s until last character from string s
   - if s[i] == open bracket
     - push s[i] into the stack
   - else
     - if st.size() == 0, then return false
     - else
       - if (st.top() == '[' && s[i] != ']'), then return false
       - else if (st.top() == '{' && s[i] == '}'), then return false
       - else if (st.top() == '(' && s[i] == ')'), then return false
       - else
         - st.pop()
3. return st.size() == 0

Time Complexity : O(N)
N -> size of string s

Memory Complexity : O(N / 2) -> O(N)
N -> size of string s

# Can we improve the memory complexity ? 
1. yes we can, the reason why iam using stack to solve the problem, is because of i need to maintain the state. So to reduce the memory complexity, we can use two pointer to maintain the state 

# Using Two Pointer
1. initialize variables
   - left = 0
   - right = 0
2. while right < s.length()
   - if s[right] == open bracket
     - change s[left] to s[right]
     - increase the left pointer
   - else
     - if left == 0, then return false (the reason is because of total open brakcet < total close bracket)
     - if (s[left - 1] == '[' && s[right] != ']'), return false
     - else if (s[left - 1] == '{' && s[right] == '}'), then return false
     - else if (s[left - 1] == '(' && s[right] == ')'), then return false
     - else
       - left--
   - increase the right pointer by 1
3. return left == 0
   - because if the input is valid, left pointer must be in 0 index position and right pointer must be in s.length() index position

Time Complexity : O(N)
N -> length of string s

Memory Complexity : O(1)
 
*/

class Solution {
private:
    bool isOpenBracket(char symbol) {
        return symbol == '[' || symbol == '{' || symbol == '(';
    }
public:
    bool isValid(string s) {
        int left = 0;
        int right = 0;

        while (right < s.length()) {
            if (isOpenBracket(s[right])) {
                // maintain the state
                s[left] = s[right];
                left++;
            } else {
                if (left == 0) {
                    return false;
                } else if (s[left - 1] == '[' && s[right] != ']') {
                    return false;
                } else if (s[left - 1] == '{' && s[right] != '}') {
                    return false;
                } else if (s[left - 1] == '(' && s[right] != ')') {
                    return false;
                } else {
                    // maintain the state
                    left--;
                }
            }

            right++;
        }

        return left == 0;
    }
};