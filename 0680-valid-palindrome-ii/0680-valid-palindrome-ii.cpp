/*

How to solve the problem : 

# Using Two Pointer Technique
1. initialize left pointer and right pointer
2. left = 0 and right = s.length() - 1
3. if (s[left] != s[right]), then there will be 2 possiblity
   - try to skip the left, by add left pointer by 1
   - try to skip the right, by decrease right pointer by 1
   - mark if the result is not valid, and return false

Time Complexity : O(N)
N -> size of string s

Memory Compleixty : O(1)

*/

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                break;
            }
            left++;
            right--;
        }

        if (left < right) {
            int tempLeft = left + 1;
            int tempRight = right;
            bool valid = true;

            while (tempLeft < tempRight) {
                if (s[tempLeft] != s[tempRight]) {
                    valid = false;
                    break;
                }

                tempLeft++;
                tempRight--;
            }

            if (valid) {
                return true;
            }

            valid = true;
            tempLeft = left;
            tempRight = right - 1;
            while (tempLeft < tempRight) {
                if (s[tempLeft] != s[tempRight]) {
                    return false;
                }

                tempLeft++;
                tempRight--;
            }

            if (valid) {
                return true;
            }

            return false;
        }

        return true;
    }
};