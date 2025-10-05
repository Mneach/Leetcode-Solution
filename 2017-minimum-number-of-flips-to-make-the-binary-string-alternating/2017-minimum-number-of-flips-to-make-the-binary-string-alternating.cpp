/*

How to solve the problem

The idea to solve the problem
1. just compare the current string with these alternating strings
   - either start from 1 or 0
   - ex : 1010101010 or 01010101001
2. count how many different characters, get the minimum one

# Using sliding window
1. initialize variables
   - left = 0
   - right = 0
   - result = INT_MAX
   - result1 = 0
   - result2 = 0
   - size = s.length()
2. create the alternating strings
   - s1, must start from 1
   - s2, must start from 0
3. while right < (size * 2) - 1
   - if (s[right % size] != s1[right % size]), then result1 += 1
   - if (s[right % size] != s2[right % size]), then result2 += 1
   - if (right >= size)
     - if (s[left % size] != s1[left % size]), then result1 -= 1
     - if (s[left % size] != s2[left % size]), then result2 -= 1
     - increase left pointer by 1
   - get the minimum result between result1 and result2
   - increaes right pointer by 1
4. return result

Time Complexity : O(N + N) -> O(N)
N -> size of string s

Memory Complexity : O(M * 2 + P * 2) -> O(N)
M -> size of string s1
P -> size of string s2

*/


class Solution {
public:
    int minFlips(string s) {
        int left = 0;
        int right = 0;
        int result = INT_MAX;
        int result1 = 0;
        int result2 = 0;
        int size = s.length();

        string s1 = "";
        string s2 = "";

        for (int i = 0; i < (size * 2) - 1; i++) {
            if (i % 2  == 0) {
                s1 += "0";
                s2 += "1";
            } else {
                s1 += "1";
                s2 += "0";
            }
        }
        

        while (right < (size * 2) - 1) {
            if (s[right % size] != s1[right]) {
                result1++;
            }

            if (s[right % size] != s2[right]) {
                result2++;
            }

            if (right >= size - 1) {
                result = min({result, result1, result2});
                if (s[left % size] != s1[left]) {
                    result1--;
                }

                if (s[left % size] != s2[left]) {
                    result2--;
                }

                left++;
            }

            right++;
        }

        return result;
    }
};