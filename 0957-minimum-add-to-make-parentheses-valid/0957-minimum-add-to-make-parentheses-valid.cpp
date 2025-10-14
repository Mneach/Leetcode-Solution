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

# Can we improve the solution ? 
1. Yes we can, instead of using stack to maintain the state, it is better to use two pointer to maintain the state, so we can reduce the memory complexity to O(1)

# Using two pointer
1. initialize variables
   - left = 0
   - right = 0
2. while right < s.length()
   - if (left == 0 || s[right] == open bracket)
     - change s[left] to s[right] to maintain the state
     - left++
   - else
     - if (s[left - 1] == open bracket && s[right] == close bracket)
       - left--
     - else
       - change s[left] to s[right] to maintain the state
       - left++
   - increase right pointer by 1
3. return left pointer

Time Complexity : O(N)
N -> length of string s

Memory Complexity : O(1)

Note : 
index 0 - left (exclusive) -> represent all of the data in stack
s[left] = s[right] && left++ -> represent push the s[i] into the stack
left == 0 -> represent stack is empty
s[left - 1] -> get the data at top of the stack

*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0;
        int right = 0;
        
        while (right < s.length()) {
            if (left == 0 || s[right] == '(' ) {
                s[left] = s[right];
                left++;
            } else {
                if (s[left - 1] == '(' && s[right] == ')') {
                    left--;
                } else {
                    s[left] = s[right];
                    left++;
                }
            }

            right++;
        } 

        return left;
    }
};