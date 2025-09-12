/*

How to solve the problem : 
1. every time we meet a space character we will try to check how many character the we have and put that into the answer variable

edge cases :
1. what if the string only contain 1 word without any spaces
   - if that the cases, we will add additional condition to check how many character that we have and put that into the answer variable

Time complexity : O(N)
N -> length of string

Memory complexity : O(1)

*/


class Solution {
public:
    int lengthOfLastWord(string s) {
        int answer = 0;        
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            char character = s[i];

            if (character == ' ') {
                if (count != 0) {
                    answer = count;
                }

                count = 0;
            } else {
                count++;
            }
        }

        if (count != 0) answer = count;

        return answer;
    }
};