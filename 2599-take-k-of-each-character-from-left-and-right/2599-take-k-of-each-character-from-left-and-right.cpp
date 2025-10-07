/*

How to solve the problem

Main Idea : 
1. find the window that we need to remove so the rest of the subarray (subArray[0...L] && subArray[R... nums.size() - 1]) can satify the condition based on the problem description

# Using sliding window
1. initialize variables
   - left = 0
   - right = 0
   - result = INT_MAX
   - a = 0
   - b = 0
   - c = 0
2. we need to count how many times a, b, and c appear in string s
3. if a or b or c < k
   - we need to return -1, because we know that the answer is gonna be invalid
4. while right < s.length()
   - if (s[right] == a) a--
   - else if (s[right] == b) b--
   - else (s[right] == c) c--
   - if (a >= 0 && b >= 0 && c >= 0)
     - valid subarray, than we need to get the result using this formula
       - formula : result = min(result, (left + (s.length() - right - 1)))
   - else
     - while (a < 0 || b < 0 || c < 0)
       - if (s[left] == a) a++
       - else if (s[left] == b) b++
       - else c++
       - increase the left pointer by 1
    - increase the right pointer by 1
5. return the result

Time Complexity : O(N + N)
N -> length of string s
first N -> to compute how many times a, b, and c, appear in string s
second N -> because we need to loop from right = 0 until nums.size() - 1

Memory Complexity : O(1)

*/

class Solution {
public:
    int takeCharacters(string s, int k) {
        int left = 0; 
        int right = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        int size = s.length();
        int result = size;

        for (auto x : s) {
            if (x == 'a') {
                a++;
            } else if (x == 'b') {
                b++;
            } else {
                c++;
            }
        }

        a -= k;
        b -= k;
        c -= k;

        if (a < 0 || b < 0 || c < 0) {
            return -1;
        }

        while (right < size) {
            if (s[right] == 'a') a--;
            else if (s[right] == 'b') b--;
            else c--;

            if (a >= 0 && b >= 0 && c >= 0) {
                result = min(result, left + (size - right - 1));
            } else {
                while (a < 0 || b < 0 || c < 0) {
                    if (s[left] == 'a') a++;
                    else if (s[left] == 'b') b++;
                    else c++;
                    left++;
                }
            }

            right++;
        }

        return result;
    }
};