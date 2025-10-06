
/*

How to solve the problem

# Using sliding window
1. initalize variables
   - left = 0
   - right = 0
   - result = 0
2. loop from the first index of string until last index of string
   - if (s[right] != t[left])
     - decrease maxCost by |s[right] - t[right]|
   - while maxCost < 0
     - if (s[left] != t[left])
       - increase the maxCost by |s[left] - t[left]|
       - increase the left pointer by 1
   - get the result using this formula
     - result = max(result, (right - left) + 1)
   - increaes the right pointer by 1
3. return the result

Time Complexity : O(N + N)
N -> length of string s

Memory Compelxtiy : O(1)

*/

class Solution {
private:
    int calculateDistance(char x, char y) {
        return abs(x - y);
    }
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int right = 0;
        int result = 0;

        while (right < s.length()) {
            if (s[right] != t[right]) {
                maxCost -= calculateDistance(s[right], t[right]);
            }

            while (maxCost < 0) {
                if (s[left] != t[left]) {
                    maxCost += calculateDistance(s[left], t[left]);
                }

                left++;
            }

            result = max(result, (right - left) + 1);
            right++;
        }

        return result;
    }
};