class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index; // Maps value to its index
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen = 0;

        // Store index of each number for quick lookup
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int prev = arr[j] - arr[i]; // The expected previous number
                
                if (prev < arr[i] && index.count(prev)) { // Ensure it's a valid Fibonacci sequence
                    int k = index[prev]; // Get index of previous number
                    dp[i][j] = dp[k][i] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }

        return maxLen > 0 ? maxLen + 2 : 0; // Add 2 to include the first two numbers
    }
};