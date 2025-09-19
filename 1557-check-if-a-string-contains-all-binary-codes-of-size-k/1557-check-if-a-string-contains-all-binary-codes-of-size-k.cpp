/*

How to solve the problem : 

# Using hashtable + Bit Manipulation
1. Loop from the first index of the s until last index of the s
2. For every process we need to do these steps
   - if s[right] == '1'
     - currentResult = (currentResult << 1) + 1
   - else 
     - currentResult = (currentResult << 1)
   - if the distance between right and left pointer == k, then 
     - put the current result into the hashtable
     - if the s[left] == '1', then we need to decreaes the current result by (2^k) - 1, since we want to eliminante the most left index
   - increase the left pointer by 1
3. Loop from 0 until (2^K) - 1
4. For every process we just need to check if the current number exists in the hashtable
   - if the current number is not exists in hashtable return false

Time Complexity : O(N + (2^k) - 1)
N -> size of the string s
first -> because we want to create the substring with size K and put the current binary result into the hashtable
2^K - 1 -> because we need to generate all of the binary code combinations with size K

Memory Complexity : O(M)
M -> size of hashtable -> worst case (2^K) - 1, since there is a case when we need to create all of the combinations

*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<int,int> hashTable;
        
        int currentResult = 0;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {

            if (s[right] == '1') {
                currentResult = (currentResult << 1) + 1;
            } else {
                currentResult = (currentResult << 1);
            }

            if ((right - left) + 1 == k) {
                hashTable[currentResult]++;

                if (s[left] == '1') {
                    // 1 << (k - 1) == 2^(k - 1)
                    currentResult = currentResult - (1 << (k - 1));
                }

                left++;
            }
        }

        for (int i = 0; i < (1 << k); i++) {
            if (hashTable[i] == 0) {
                return false;
            }
        }

        return true;
    }
};