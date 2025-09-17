/*

How to solve the problem : 

1. Loop from first indexo f S until last index of S
2. for every index we need to check wheather s[i] value is '[' or ']'
   - if s[i] is '[', count decrease by 1
   - if s[i] is ']', count increase by 1 

Note : 
1. The definition of count is how many unmatch bracket in string s

Time Complexity : O(N)
N -> size of string s

Memory Complexity : O(1)


*/

class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        int unmatchBracket = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                count--;
            } else {
                count++;
            }

            unmatchBracket = max(unmatchBracket, count);
        }

        return (unmatchBracket / 2) + (unmatchBracket % 2);
    }
};