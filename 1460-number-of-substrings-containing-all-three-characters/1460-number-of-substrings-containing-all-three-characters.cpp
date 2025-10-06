/*

How to solve the problem

# Using Greedy
1. initalize variables
   - a = -1
   - b = -1
   - c = -1
   - result = 0
2. loop from first index of string until last index of string
   - if (s[i] == 'a') a = i
   - else if (s[i] == 'b') b = i
   - else if (s[i] == 'c') c = i
   - get minimum value between (a, b, and c)
   - if the minimum value >= 0
     - result += (minimum value) + 1
3. return the result

Time Compelexity : O(N)
N -> length of string s

Memory Complexity : O(1)

*/


class Solution {
public:
    int numberOfSubstrings(string s) {
       int a = -1;
       int b = -1;
       int c = -1;
       int result = 0;

       for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                a = i;
            } else if (s[i] == 'b') {
                b = i;
            } else if (s[i] == 'c') {
                c = i;
            }

            int minimum = min(a, min(b, c));

            if (minimum >= 0) {
                result += minimum + 1;
            }
       }

       return result;
    }
};