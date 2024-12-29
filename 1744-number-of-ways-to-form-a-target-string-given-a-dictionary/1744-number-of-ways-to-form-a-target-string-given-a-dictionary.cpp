#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int mod = 1e9 + 7;
        int wordLength = words[0].size();
        int targetLength = target.size();

        // Initialize DP table and character frequency table.
        vector<vector<long>> dp(wordLength, vector<long>(targetLength, -1));
        vector<vector<int>> charFrequency(wordLength, vector<int>(26, 0));

        // Populate character frequency table.
        for (const string& word : words) {
            for (int j = 0; j < wordLength; ++j) {
                charFrequency[j][word[j] - 'a']++;
            }
        }

        // Start the recursive computation.
        return getWays(0, 0, target, dp, charFrequency, mod);
    }

private:
    long getWays(int wordIndex, int targetIndex, const string& target,
                 vector<vector<long>>& dp, const vector<vector<int>>& charFrequency, int mod) {
        // Base case: successfully formed the target string.
        if (targetIndex == target.size()) {
            return 1;
        }

        // Base case: reached the end of word columns without forming the target.
        if (wordIndex == charFrequency.size() || 
            charFrequency.size() - wordIndex < target.size() - targetIndex) {
            return 0;
        }

        // Return the cached result if available.
        if (dp[wordIndex][targetIndex] != -1) {
            return dp[wordIndex][targetIndex];
        }

        long countWays = 0;

        // Case 1: Skip the current word column.
        countWays += getWays(wordIndex + 1, targetIndex, target, dp, charFrequency, mod);

        // Case 2: Use the current word column to match the target character.
        int targetChar = target[targetIndex] - 'a';
        countWays += (long)charFrequency[wordIndex][targetChar] * 
                     getWays(wordIndex + 1, targetIndex + 1, target, dp, charFrequency, mod);

        // Store the result in the DP table and return it modulo mod.
        return dp[wordIndex][targetIndex] = countWays % mod;
    }
};
