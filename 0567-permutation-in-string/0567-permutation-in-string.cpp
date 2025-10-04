/*

How to solve the problem 

# Using Sliding Window
1. initialize variables
   - left = 0
   - right = 0
   - hashtable with key = character, and value = total character
2. loop from the first index of s1 until last index of s1
   - hashTable[s1[i]]++
3. loop from the first index of s2 until last index of s2
   - if (hashTable.count(s2[right]) == 0)
     - move left pointer to right pointer
       - if (hashTable.count(s2[left]) > 0), then increase the hashtable value
   - else
     - hashTable[s2[right]]--
     - while (hashTable[s2[right]] < 0)
       - move the left pointer until hashTable[s2[right]] == 0
     - loop for every data in hashtable, if all of the value == 0, then return true

Time Complexity : O(N + (M * P^2)
N -> length of string s1
M -> length of string s2
P -> total different characters in hashtable -> worstcase = 26

Memory Complexity : O(P)
P -> total different characters in hashtable

*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;        
        int right = 0;
        unordered_map<char,int> hashTable;
        
        for (auto c : s1) {
            hashTable[c]++;
        }

        while (right < s2.length()) {
            if (hashTable.count(s2[right]) == 0) {
                // move left pointer to right pointer
                while (left < right) {
                    if (hashTable.count(s2[left]) > 0) {
                        hashTable[s2[left]]++;
                    }
                    left++;
                }
            } else {
                hashTable[s2[right]]--;

                while (hashTable[s2[right]] < 0) {
                    if (hashTable.count(s2[left]) > 0) {
                        hashTable[s2[left]]++;
                    }
                    left++;
                }

                bool valid = true;
                for (auto [key, value] : hashTable) {
                    if (value != 0) {
                        valid = false;
                    }
                }

                if (valid) {
                    return true;
                }
            }

            right++;
        }

        return false;
    }
};