/*

How to solve the problem : 
idea : 
- odd + even = odd
- odd + odd = even
- even + even = even

To create the odd sum, we need to have atleast (1, 3, 5, ...), where n value start from 1

1. Define variable, currentResult, prevOddResult, twoPrevOddResult
2. Loop from the first index until the last index, need to do these steps
   - count how many even number that we have until we meet odd number
   - if we meet odd number, we can compute by using this formula
      formula : ((totalEven + 1) + twoPrevOddResult) % 10^9 + 7
   - update twoPrevoddResult = prevOddResult
   - prevOddResult = currentResult
   - currentResult = totalEven + 1 + twoPrevOddResult
   - dont forget to use module by 10^9 + 7

Time Complexity : O(N)
N -> size of arr

Memory Complexity : O(1)

*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int answer = 0;
        int currentResult = 0;
        int prevOddResult = 0;
        int prevTwoOddResult = 0;

        int totalEven = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 == 0) {
                totalEven++;
            } else {
                currentResult = ((totalEven + 1) + prevTwoOddResult) % mod;
                prevTwoOddResult = prevOddResult;
                prevOddResult = currentResult;
                totalEven = 0;
            }

            answer = (answer + currentResult) % mod;
        }        

        return answer;
    }
};