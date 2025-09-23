/*

How to solve the problem : 

# Using two pointer technique
1. initialize left pointer and right pointer
2. left = 0 and right = 0
3. loop until left < word1.length and right < word2.length
4. loop again the rest of word1 character
5. loop again the rest of word 2 character

Time Complexity : O(max(N, M) - min(N, M)) -> O(N)
N -> size of word1 
M -> size of word2

Memory Complexity : O(1)

*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer = "";
        int left = 0;
        int right = 0;

        while (left < word1.length() && right < word2.length()) {
            answer += word1[left];
            answer += word2[right];
            left++;
            right++;
        }

        while (left < word1.length()) {
            answer += word1[left];
            left++;
        }

        while (right < word2.length()) {
            answer += word2[right];
            right++;
        }

        return answer;
    }
};