/*

How to solve the problem

# Using Stack
1. initialize variables
   - stack<char> st
   - result = ""
2. loop for every index from 0 until s.length() - 1
   - if s[i] is uppercase letter
     - x = change s[i] to lower case letter
     - if stack.size() > 0 && stack.top() == x, then remove the data from stack (stack.pop())
     - else push s[i] into the stack
   - else 
     - x = change s[i] to the upper case
     - if stack.size() > 0 && stack.top() == x, then remove the data ffrom stack (stack.pop())
     - else push s[i] into the stack
3. loop for every data in the stack, push the data into the result string
4. return the result

Time Complexity : O(N + M + M) -> O(N)
N -> size of string
M -> size of stacks

Memory Complexity : O(M)
M -> size of stacks

# Can we improve the solution ? 
1. Yes we can, instead of using stack to control the state, it is better to use two pointer to control the state, so we can reduce the memory complexity to O(1)

# Using Two Pointer
1. initialize variables
   - left = 0
   - right = 0
   - result = ""
2. while right < s.length()
   - if s[right] is upper case letter
     - x = change s[right] to lower case letter
     - if left > 0 && s[left - 1] == x
     - else
       - change s[left] with s[right]
       - increase the left pointer
   - else
     - x = change s[right] to upper case letter
     - if left > 0 && s[left - 1] == x
     - else
       - change s[left] with s[right]
       - increase the left pointer
   - increase right pointer by 1
3. loop from index 0 until l to get the result
4. return the result

Time Complexity : O(N + M)
N -> length of string s
M -> left pointer value

Memory Complexity : O(1)

Notes : 
left > 0 = stack is not empty
s[left - 1] = top data in the stack
index 0 - L = represent the data in the stack
left -= 1 = pop data from the stack
left += 1 = push data into the stack

*/


class Solution {
private:
    bool isUpperCaseLetter(char x) {
        return x >= 'A' && x <= 'Z';
    }    
public:
    string makeGood(string s) {
        string result = "";
        int left = 0;
        int right = 0;

        while (right < s.length()) {
            if (isUpperCaseLetter(s[right])) {
                if (left > 0 && s[left - 1] == (s[right] - 'A') + 'a') {
                    left--;
                } else {
                    s[left] = s[right];
                    left++;
                }
            } else {
                if (left > 0 && s[left - 1] == (s[right] - 'a') + 'A') {
                    left--;
                } else {
                    s[left] = s[right];
                    left++;
                }
            }
            
            right++;
        }

        for (int i = 0; i < left; i++) {
            result += s[i];
        }

        return result;
    }
};