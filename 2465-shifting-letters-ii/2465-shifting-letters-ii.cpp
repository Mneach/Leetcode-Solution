/*

How to solve the problem : 

Brute Force Solution
1. For every character in string s, we need to find if the current index is include in the shift array, after that change the current index character based on the shift[i] direction

Time Complexity : O(N * N * M)
N -> size of string s
M -> size of shifts array

First N -> Because we need to loop for every character in s 
Second N -> Because we need to loop from shifts[i] start until shifts[i] end
Third M -> Becase we neeed to loop from first index of shifts until last index of shifts

Memory Complexity : O(1)

What makes the algorithm run slowly ? 
1. Because for every character we need to loop from first index of the shifts array until last index of the shifts array

How to improve ? 
1. What if we just mark the start and end from every data in the shifts array based on the direction value.
2. if start = 2, end = 5, and direction = 1, that means from index 2 until index 5 we need to add by 1, will mark start - 1 which is index 1 with -1, the reason is because of we will do the prefix sum from right index of the array until left index of the array, its something like cleanup the rest of the array that no included in start and end array

# Using Prefix Sum 
1. Create an array with size equal to S, lets call it prefixSum
2. Loop from the first index of shifts array until last index of shifts array
3. add prefixSum[end] by 1
4. check if the start != 0, then minus prefixSum[start] by 1
5. Loop from the right index of prefixSum array until left index of prefix sum array
6. Add the current result value with prefiSum[i]
7. Change the s[i] based on the current result value, we can use this formula
   - formula : (s[i] - 'a') + currentResult) % 26) + 'a'
   - since the result of s[i] + prefixSum[i] can be negative, we need to change to formula to become like this : (((s[i] - 'a') + currentResult) % 26) + 'a'
8. return string s

Time Complexity : O(N + M)
N -> size of prefix sum array
M -> size of shifts array

Memory Complexity : O(N)
N -> size of prefix sum array

*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<long long> prefixSum(s.length(), 0);        

        for (auto shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int value = shift[2];

            if (start != 0) {
                if (value == 1) {
                    prefixSum[start - 1] -= 1;
                } else {
                    prefixSum[start - 1] += 1;
                }
            }

            if (value == 1) {
                prefixSum[end] += 1;
            } else {
                prefixSum[end] -= 1;
            }
        }

        int currentResult = 0;

        for (int i = prefixSum.size() - 1; i >= 0; i--) {
            currentResult += prefixSum[i];
            currentResult %= 26;
            
            int number = (((s[i] - 'a') + currentResult) + 26) % 26;
            s[i] = number + 'a';
        }

        return s;
    }
};