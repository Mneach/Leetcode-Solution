/*

How to solve the problem

Main Idea : 
1. Instead of find exactly k consonant, its will be easy if we just find atleast k consonant
   - so to get exact consonant, we just need to find the substring with atleast k consonant and atleast k + 1 consonant
   - decrease the result from atleast k consonant with atleast k + 1 consonant
   - the result of that math formula will be = exact k consonant substrings

# Using sliding window + hashtalbe
1. create a function to get valid substrings
2. initialize variables
   - left = 0
   - right = 0
   - hashTable -> with key = vowel letters and value = how many times vowel letter appear in current substrings
   - result = 0
   - consonant = 0
   - count = 0
4. while right < word.size()
   - if current character is vowel, then put that character into the hashtable
   - else add consonant value by 1
   - while (consonant == k && hashTable.size() == 5)
     - count++
     - if word[left] is vowel, then decrease hashTable[word[left]] by 1
     - else decrease the consonant by 1
     - if hashTable[word[left]] == 0, then remove that character from hashtable
   - add the result by count
5. return getValidSubstring(word, k) - getValidSubstring(word, k + 1)

Time Complexity : O(N + N)
N -> length of word 

Memory Complexity : O(1)

*/

class Solution {
private:

    bool isVowel(char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }

    long long getValidSubStrings(string &word, int k) {
        unordered_map<char,int> hashTable;
        int left = 0;
        int right = 0;
        int consonant = 0;
        long long count = 0;
        long long result = 0;

        while (right < word.length()) {
            if (isVowel(word[right])) {
                hashTable[word[right]]++;
            } else {
                consonant++;
            }

            while (consonant >= k && hashTable.size() == 5) {
                count++;
                if (isVowel(word[left])) {
                    hashTable[word[left]]--;
                } else {
                    consonant--;
                }

                if (hashTable[word[left]] == 0) {
                    hashTable.erase(word[left]);
                }
                left++;
            }

            result += count;

            right++;
        }

        return result;
    }
public:
    long long countOfSubstrings(string word, int k) {
       return getValidSubStrings(word, k) - getValidSubStrings(word, k + 1); 
    }
};