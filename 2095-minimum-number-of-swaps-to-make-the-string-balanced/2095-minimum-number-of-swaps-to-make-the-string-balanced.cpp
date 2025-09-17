/*

How to solve the problem : 
1. loop from first index of s until last index of s
2. if we meet the unmatch bracket we need to store the current count to the count variable
   - umatch bracket = "]["
3. if we meet match bracket we need to decrease the current count by 1, since we will ignore the match bracket
   - match bracket = "[]"
4. to calculate how many minumum swap that we need, we can use this formula
   - formula : (n / 2) + (n % 2)
   - n / 2 -> because of for every swap, the best case scenario is to get 2 match bracket
   - n % 2 -> because of for every odd count value, we need to add + 1 swap operation

Time Complexity : O(N)
N -> size of string S

Memory Complexity : O(1)

*/

class Solution {
public:
    int minSwaps(string s) {
        int count = 0;        
        int currentCount = 0;

        for (int i = 0; i < s.length(); i++) {

            if (i > 0 && s[i - 1] == ']' && s[i] == '[' && currentCount < 0) {
                count += abs(currentCount);
                currentCount = 0;
            }
            
            if (s[i] == '[') {
                currentCount++;
            } else {
                currentCount--;
            }

        }

        if (currentCount != 0) {
            count += currentCount;
        }

        int unmatchBracket = count / 2;

        return (unmatchBracket / 2) + (unmatchBracket % 2);
    }
};