/*

How to solve the problem : 

# Using bit masking

1. To check if two palindromes are disjoint we can use this bitmask
Transform leetcode word to bitmask
leetcodecom 
00000000000

let assume we have these two palindromes :
leetcodecom 
00000000000
 e t   e
01010001000

leetcodecom
00000000000
    c d c
00001010100

to know if those two palindromes are disjoint, we can use AND operation, if the result of AND operation == 0, the those palindromes are disjoin

01010001000 -> ete
00001010100 -> cdc
------------------- &
00000000000 -> that means those two palindromes are disjoint

2. To create all of the subsequence from string S we need to loop from 1 until 1 << N
- the reason start from 1 is because 2^0 = 1
- for every mask result, we need to loop again to cover that mask into the string
- to convert mask into the string we just need to check if mask & 1 << N == 1, then add s[i] to the string sub seq
- if that subsequence is palindrome, then put that subsequance to the hashtable with key = subsequance and value = length of subsequance 

3. To get the answer, need to loop the palindrome hashtable, and if these two palindrome are disjoint, then return length of palindrome 1 * length of palindrome 2

Time Complexity : O(2^M)^2 = O(4^M)
M -> 1 << N

memory Complexity : O(2^M)
M -> 1 << N

*/

class Solution {
public:
    int maxProduct(string s) {
        unordered_map<long long,int> hashTable;
        int size = s.length();
        
        for (long long mask = 1; mask < (1 << size); mask++) {
           string subSequance = "";

           for (int j = 0; j < size; j++) { 

                // check if the j'th bit is live
                if ((mask & (1 << j) ) != 0) {
                    subSequance += s[j];
                }
           }

           // check palindrome
           bool valid = true;
           int left = 0;
           int right = subSequance.size() - 1;
           while (left < right) {
            if (subSequance[left] != subSequance[right]) {
                valid = false;
                break;
            }

            left++;
            right--;
           }

           if (valid) {
            hashTable[mask] = subSequance.length();
           }
        }

        // get the answer
        int answer = 0;
        for (auto data : hashTable) {
            int firstKey = data.first;
            int firstValue = data.second;

            for (auto data2 : hashTable) {
                int secondKey = data2.first;
                int secondValue = data2.second;

                if ((firstKey & secondKey) == 0) {
                    answer = max(answer, firstValue * secondValue);
                }
            }
        }

        return answer;
    }
};