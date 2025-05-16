class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n = words.size();
        vector<int> dp(n, 1);          // dp[i] = length of longest subsequence ending at i
        vector<int> prev(n, -1);       // prev[i] = index of previous word in subsequence
        int max_index = 0;             // index of the longest subsequence found
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (is_valid_pair(words[i], words[j]) && 
                    groups[i] != groups[j] && 
                    dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            
            if (dp[i] > dp[max_index]) {
                max_index = i;
            }
        }
        
        return reconstruct_subsequence(words, prev, max_index);
    }

private:
    // Check if two words form a valid pair (same length, exactly one differing character)
    bool is_valid_pair(const string& a, const string& b) const {
        if (a.length() != b.length()) return false;
        
        int differences = 0;
        for (size_t i = 0; i < a.length() && differences <= 1; ++i) {
            if (a[i] != b[i]) ++differences;
        }
        
        return differences == 1;
    }
    
    // Reconstruct the subsequence from the prev array
    vector<string> reconstruct_subsequence(const vector<string>& words, 
                                         const vector<int>& prev, 
                                         int end_index) const {
        vector<string> subsequence;
        for (int i = end_index; i >= 0; i = prev[i]) {
            subsequence.push_back(words[i]);
        }
        reverse(subsequence.begin(), subsequence.end());
        return subsequence;
    }
};