/*

How to solve the problem

# Using two pointer techcnique
1. Initialize left and right pointer (left = s.length() - 1 && right = t.length() - 1)
2. while left >= 0 && right >= 0
   - find next valid character for string s
   - find next valid character for string t
   - if charS != charT return false
   - decrease left index by 1
   - decrease right index by 1

Time Complexity : O(N + M)
N -> size of s
M -> size of t

Memory Complexity : O(1)

*/

class Solution {
private:
    int findValidNextChar(string &s, int currentIndex) {
        int backSpace = 0;

        while (currentIndex >= 0) {
            if (s[currentIndex] == '#') {
                backSpace++;
            } else if (backSpace > 0) {
                backSpace--;
            } else {
                break;
            }

            currentIndex--;
        }

        return currentIndex;
    }
public:
    bool backspaceCompare(string s, string t) {
        int left = s.length() - 1;
        int right = t.length() - 1;

        while (left >= 0 || right >= 0) {
            int indexS = findValidNextChar(s, left);
            int indexT = findValidNextChar(t, right);

            char charS;
            char charT;

            if (indexS < 0) {
                charS = '\0';
            } else {
                charS = s[indexS];
            }

            if (indexT < 0) {
                charT = '\0';
            } else {
                charT = t[indexT];
            }

            if (charS != charT) {
                return false;
            }

            left = indexS - 1;
            right = indexT - 1;
        }

        return true;
    }
};