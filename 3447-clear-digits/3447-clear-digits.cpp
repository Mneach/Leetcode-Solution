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

# Can we improve the solution
1. Yes we can, instead of using stack to maintain the state, we can use two pointer to maintain the state

# Note
index 0 - L = represent all of the data in stack
s[left] = s[right] && left++ = represent push s[i] into the stack
left-- = represent pop s[i] from the stack
s[left - 1] = data in the top of the stack
left == 0 = represent stack is empty

# Using Two Pointer
1. initialzie variables
   - left = 0
   - right = 0
2. while right < s.length()
   - if left == 0
     - s[left] = s[right]
     - left++
   - else if s[left - 1] is a non digit and s[right] is a digit
     - decrease the left pointer by 1
   - else
     - s[left] = s[right]
     - left++
3. loop from index 0 until left pointer value
   - result += s[i]
4. return the result

Time Complexity : O(N)
N -> length of s

Memory Complexity : O(1)

*/

class Solution {
    bool isDigit(char x) {
        return x >= '0' && x <= '9';
    }
public:
    string clearDigits(string s) {
        int left = 0;
        string result = "";

        for (int right = 0; right < s.length(); right++) {
            if (left == 0) {
                s[left] = s[right];
                left++;
            } else if (isDigit(s[left - 1]) == false && isDigit(s[right]) == true) {
                left--;
            } else {
                s[left] = s[right];
                left++;
            }
        }

        for (int i = 0; i < left; i++) {
            result += s[i];
        }

        return result;
    }
};