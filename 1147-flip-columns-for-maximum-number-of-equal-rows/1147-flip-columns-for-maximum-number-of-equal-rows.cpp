class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternFrequency;

        for (const auto& row : matrix) {
            string pattern;
            for (int val : row) {
                pattern += (val == row[0]) ? 'T' : 'F';
            }
            patternFrequency[pattern]++;
        }

        int maxFrequency = 0;
        for (const auto& [pattern, freq] : patternFrequency) {
            maxFrequency = max(maxFrequency, freq);
        }

        return maxFrequency;
    }
};
