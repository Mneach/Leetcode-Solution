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

Memory Complexty : O(M)
M -> total unique characters in hashtable

# What makes the algorithm run slowly ? 
1. because we need to move the left pointer

# How to improve the problem ? 
1. instead of moving the left pointer to remove the character from hashtable, it is better to move directly the left pointer to hashTable[s[right]] + 1. The reason is because of after we move the left pointer to hashTable[s[right]] + 1, all of the characters before that is useless

# Using sliding window optimal
1. Initialize left, right, result variables (left = 0, right = 0, result = 0)
2. Initialize hashtable -> key = character, value = index
3. loop from the first index of s until last index of s
    - if (hashtable.count(s[right]) > 0)
     - move the left pointer to hashtable[s[right]] + 1
   - add s[right] into the hashtable
   - get the maximum result (result = max(result, (right - left) + 1)
   - increase right pointer by 1

Time Complexity : O(N)
N -> size of string s
First N -> because we need to loop from first index of s until last index
Second N -> becase we need to loop from current left pointer until hashTable[s[right]] + 1 index

Memory Complexty : O(M)
M -> total unique characters in hashtable

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
                left = max(hashTable[s[right]] + 1, left);
            }

            hashTable[s[right]] = right;
            result = max(result, (right - left) + 1);
            right++;
        }
        
        return result;
    }
};