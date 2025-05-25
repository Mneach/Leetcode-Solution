class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int unpaired_same = 0;  // count of unpaired same-character words (like "aa", "bb")
        int length = 0;         // resulting palindrome length
        
        for (const string& word : words) {
            if (word[0] == word[1]) {
                // For same-character words
                if (freq[word] > 0) {
                    unpaired_same--;
                    freq[word]--;
                    length += 4;
                } else {
                    freq[word]++;
                    unpaired_same++;
                }
            } else {
                // For different-character words
                string reversed_word = string(1, word[1]) + word[0];
                if (freq[reversed_word] > 0) {
                    length += 4;
                    freq[reversed_word]--;
                } else {
                    freq[word]++;
                }
            }
        }
        
        // Add 2 if there's at least one unpaired same-character word
        if (unpaired_same > 0) {
            length += 2;
        }
        
        return length;
    }
};