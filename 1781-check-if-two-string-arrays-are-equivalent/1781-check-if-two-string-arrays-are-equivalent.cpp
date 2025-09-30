/*

How to solve the problem

# Using Two Pointer Technique
1. Initialize left and right pointer (left = 0 and right = 0)
2. left pointer for word1 and right pointer for word2
3. to know if the string is equal we can use this validation
   - word1[left % word1.size()] == word2[right % word2.size()], then word1 and word2 have same character at that index
   - word1[left % word1.size()] != word2[right % word2.size()], then word1 and word2 doesn't have same character at that index, we should return false

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