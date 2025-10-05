/*

How to solve the problem

# Using sliding window
1. initialize variables
   - left = 0
   - right = 0
   - totalVowel = 0
   - result = 0
2. while right < s.length()
   - if (s[right] == vowelLetter)
     - totalVowel += 1
   - if (right - left == k)
     - if (s[left] == vowelLetter)
       - totalVowel -= 1
     - increaes left pointer by 1
   - get the maximum result using this formula
     - formula : result = max(result, totalVowel)
   - increase right pointer by 1
3. return the result

Time Complexity : O(N)
N -> length of string s

Memory Complexity : O(1)

*/


class Solution {
private:
    bool isVowel(char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int left = 0;        
        int right = 0;
        int totalVowel = 0;
        int result = 0;

        while (right < s.length()) {
            if (isVowel(s[right])) {
                totalVowel++;
            }

            if (right - left == k) {
                if (isVowel(s[left])) {
                    totalVowel--;
                }
                left++;
            }

            result = max(result, totalVowel);
            right++;
        }

        return result;
    }
};