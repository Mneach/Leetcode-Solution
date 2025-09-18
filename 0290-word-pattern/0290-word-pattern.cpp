/*

How to solve the problem : 
1. Mapping pattern[i] to the word in string s, and put that into the hashtable
2. if pattern[i] is already have a value, and the value of pattern[i] in hashtable different with word from string s, then return false

Time Complexity : O(N + M)
N -> length of pattern string
M -> length of pattern s

Memory Complexity : O(N)
N -> length of pattern string

*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> hashTable;
        unordered_map<string, bool> visited;

        int indexS = 0;
        for (int i = 0; i < pattern.length(); i++) {

            // get the word from string s
            string word = "";
            while (indexS < s.length() && s[indexS] != ' ') {
                word += s[indexS];
                indexS++;
            }

            indexS++;

            if (indexS >= s.length() && i < pattern.length() - 1) {
                return false;
            }

            if (hashTable.count(pattern[i]) > 0) {
                if (hashTable[pattern[i]] != word) {
                    return false;
                }
            } else {

                if (visited[word] == true) {
                    return false;
                }

                hashTable[pattern[i]] = word;
                visited[word] = true;
            }
        }

        if (indexS < s.length()) {
            return false;
        }

        return true;
    }
};