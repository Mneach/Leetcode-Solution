/*

How to solve the problem

# Using Two Pointer Technique
1. intiialize the index (word1 index and word2 index)
2. while word1Index < word1.size() && word2Index < word2.size()
   - take word from word1
   - take word from word2
   - compare the character from word1 and word2
   - if the character is not equal return false
   - otherwise
     - increase the index by 1 for those words
     - if the index >= word.length()
     - reset the index
     - reset the flag, so we can get next word in the next iteration

Time Complexity : O(N + M)
N -> total characters in word1
M -> total characters in word2

Memory Complexity : O(1)

*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int left = 0;
        int right = 0;
        int word1Index = 0;
        int word2Index = 0;
        string w1 = "";
        string w2 = "";

        while (word1Index < word1.size() && word2Index < word2.size()) {
            if (w1 == "") {
                left = 0;
                w1 = word1[word1Index];
            }

            if (w2 == "") {
                right = 0;
                w2 = word2[word2Index];
            }

            if (w1[left] != w2[right]) {
                return false;
            }

            left++;
            right++;

            if (left >= w1.length()) {
                w1 = "";
                word1Index++;
            }

            if (right >= w2.length()) {
                w2 = "";
                word2Index++;
            }
        }

        if (word1Index >= word1.size() && word2Index >= word2.size()) {
            return true;
        }

        return false;
    }
};