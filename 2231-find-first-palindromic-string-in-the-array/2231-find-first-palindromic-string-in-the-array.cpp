/*

# Using two pointer technique
1. To know if the words[i] is palindrome, we can just put the left pointer at the first index and right pointer at the last index of word, then just need to check if word[left] != word[right] return false
2. if the checkPalindrome function return true, then we return the words[i]
3. otherwise, just need to continue to the next index

Time Complexity : O(N * M)
N -> size of words array
M -> size of word

Memory Complexity : O(1)

*/

class Solution {
private:
    bool checkPalindrome(string &word) {
        int left = 0;
        int right = word.length() - 1;

        while (left < right) {
            if (word[left] != word[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (auto word : words) {
            if (checkPalindrome(word) == true) {
                return word;
            }
        }

        return "";
    }
};