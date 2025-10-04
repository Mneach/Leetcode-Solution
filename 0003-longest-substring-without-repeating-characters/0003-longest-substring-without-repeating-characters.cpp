/*

How to solve the problem : 

# Using sliding window
1. Initialize left, right, result variables (left = 0, right = 0, result = 0)
2. Initialize hashtable -> key = character, value = index
3. loop from the first index of s until last index of s
   - if (hashtable.count(s[right]) > 0)
     - move the left pointer to hashtable[s[right]]
       - remove s[left] character from hashtable
   - add s[right] into the hashtable
   - get the maximum result (result = max(result, (right - left) + 1)
   - increase right pointer by 1

Time Complexity : O(N + N)
N -> size of string s
First N -> because we need to loop from first index of s until last index
Second N -> becase we need to loop from current left pointer until hashTable[s[right]] + 1 index

Memory Complexty : O(1)

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> hashTable;
        int left = 0;
        int right = 0;
        int result = 0;

        while (right < s.length()) {
            if (hashTable.count(s[right]) > 0) {
                // move left pointer until hashTable[s[right]] + 1 
                while (left < hashTable[s[right]] + 1) {
                    hashTable.erase(s[left]);
                    left++;
                }
            }

            hashTable[s[right]] = right;
            result = max(result, (right - left) + 1);
            right++;
        }
        
        return result;
    }
};