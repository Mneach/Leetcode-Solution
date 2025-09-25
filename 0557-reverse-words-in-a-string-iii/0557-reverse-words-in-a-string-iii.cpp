/*

How to solve the problem

1. Loop from first index of string s until last index of string s
2. Put the left pointer at the left of word and right pointer at the right of word
3. Swap left pointer and right pointer
4. increaes left pointer and decrease right pointer

Time Complexity : O(N)
N -> size of string s

Memory Complexity : O(1)

*/

class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = 0;

        while (right < s.length()) {
            if (s[right] == ' ') {
                int temp = right - 1;

                while (left < temp) {
                    swap(s[left], s[temp]);
                    left++;
                    temp--;
                }

                left = right + 1;
            }

            right++;
        }

        while (left < right) {
            right--;
            swap(s[left], s[right]);
            left++;
        }

        return s;
    }
};