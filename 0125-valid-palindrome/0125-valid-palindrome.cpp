/*

How to solve the problem :

# Using two pointer technique
1. intialize the left pointer and right pointer
2. left = 0 and right = s.length() - 1 (last index of string s)
3. loop from first index until left > right
4. if s[left] is not a letter, just increaes the left pointer by 1
5. if s[right] is not a letter, just decrease the right pointer by 1
6. if (left < right)
   - if s[left] is not a lowercase letter, then convert to lower case
   - if s[right] is not a lowercase letter, then covnert to the lowercase
   - if s[left] != [right] return false

Time Complexity : O(N)
N -> length of string

Memory Complexity : O(1)

*/

class Solution {
private:
    bool isLetter(char x) {
        return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9');
    }
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            
            while (left < s.length() && isLetter(s[left]) == false) {
                left++;
            }

            while (right >= 0 && isLetter(s[right]) == false) {
                right--;
            }

            if (left < right) {

                if (s[left] >= 'A' && s[left] <= 'Z') {
                    s[left] = tolower(s[left]);
                } 

                if (s[right] >= 'A' && s[right] <= 'Z') {
                    s[right] = tolower(s[right]);
                }

                if (s[left] != s[right]) {
                    return false;
                }
            }

            left++;
            right--;
        }

        return true;
    }
};