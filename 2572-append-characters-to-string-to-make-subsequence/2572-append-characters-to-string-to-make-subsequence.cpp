/* 

How to solve : 

# Using two pointer technique
1. we need to check if s[indexS] == t[indexT]
   - if thats equal, we need to increase indexS and indexT
   - otherwise, we just need to increase indexS
2. to compute the answer, we can use this formula
   - answer = t.length() - indexT

time complexity : O(N)
N -> min(s.length(), t.length())

memory complexity : O(1)

*/


class Solution {
public:
    int appendCharacters(string s, string t) {
        int indexS = 0;        
        int indexT = 0;

        while (indexS < s.length() && indexT < s.length()) {
            if (s[indexS] == t[indexT]) {
                indexS++;
                indexT++;
            } else {
                indexS++;
            }
        }

        return t.length() - indexT;
    }
};