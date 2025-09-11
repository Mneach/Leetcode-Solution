/*

How to solve the problem

# Two Pointer Technique
1. Loop for every character in s and t
   - if s[indexS] == t[indexT], then increase indexS and indexT by 1
   - otherwise indexT by 1
2. to find the answer we need to check if indexS == s.length()

Time Complexity : O(min(s.length(), t.length)) -> O(N)
N = min(s.length(), t.length())

Memory Comlexity : O(1)

*/


class Solution {
public:
    bool isSubsequence(string s, string t) {

        int indexS = 0;        
        int indexT = 0;

        while (indexS < s.length() && indexT < t.length()) {
            
            if (s[indexS] == t[indexT]) {
                indexS++;
                indexT++;
            } else {
                indexT++;
            }
        }

        return s.length() == indexS;
    }
};