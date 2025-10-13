/*

How to solve the problem 

# Using stack
1. initialize variables
   - stack<char> stack
2. loop from first index of string s until last index of string s
   - if stack empty
     - push s[i] into the stack
   - else if stack.top() == 'A' && s[i] == 'B'
     - stack.pop()
   - else if stack.top() == 'C' && s[i] == 'D'
     - stack.pop()
   - else
     - push the s[i] into the stack
3. return stack.size()

Time Complexity : O(N)
N -> length of string s

Memory Complexity : O(M)
M -> size of stack

# Can we improve the solution ? 
1. Yes we can improve the solution, Instead of using stack to maintain the result string, we can use two pointer to maintain the state

# Note
- Index 0 - left -> will be represent the data in the stack
- s[left - 1] -> top of the stack
- left -= 1 -> represent pop the data from stack
- s[left] = s[right] && left += 1 -> represent push the data to stack

# Using Two Pointer
1. initialize variables
   - left = 0
   - right = 0
2. while right < s.length()
   - if (left == 0) 
     - s[left] = s[right]
     - left++
   - else if (s[left - 1] == 'A' && s[right] == 'B')
     - left--
   - else if (s[left - 1] == 'C' && s[right] == 'D')
     - left--
   - else
     - s[left] = s[right]
     - left++
3. return left pointer

Time Complexity : O(N)
N -> length of string s

Memory Complexity : O(1)

*/

class Solution {
public:
    int minLength(string s) {
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            if (left == 0) {
                s[left] = s[right];
                left++;
            } else if (s[left - 1] == 'A' && s[right] == 'B') {
                left--;
            } else if (s[left - 1] == 'C' && s[right] == 'D') {
                left--;
            } else {
                s[left] = s[right];
                left++;
            }
        }

        return left;
    }
};