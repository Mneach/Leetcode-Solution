class Solution {
    static constexpr int MOD = 1e9 + 7;

    std::vector<int> buildConsecutiveGroups(const std::string& word) {
        std::vector<int> groups;
        if (word.empty()) return groups;

        int current_count = 1;
        for (size_t i = 1; i < word.size(); ++i) {
            if (word[i] == word[i-1]) {
                ++current_count;
            } else {
                groups.push_back(current_count);
                current_count = 1;
            }
        }
        groups.push_back(current_count);
        return groups;
    }

    long long calculateInitialTotal(const std::vector<int>& groups) {
        long long total = 1;
        for (int num : groups) {
            total = (total * num) % MOD;
        }
        return total;
    }

    long long countInvalidSequences(const std::vector<int>& groups, int k) {
        std::vector<int> dp(k, 0);
        dp[0] = 1;  // Base case: empty sequence

        for (int num : groups) {
            std::vector<int> new_dp(k, 0);
            long long rolling_sum = 0;

            for (int s = 0; s < k; ++s) {
                // Add the previous count
                if (s > 0) {
                    rolling_sum = (rolling_sum + dp[s-1]) % MOD;
                }
                // Subtract the count that's now out of window
                if (s > num) {
                    rolling_sum = (rolling_sum - dp[s-num-1] + MOD) % MOD;
                }
                new_dp[s] = static_cast<int>(rolling_sum);
            }
            dp = std::move(new_dp);
        }

        long long invalid_count = 0;
        for (int s = groups.size(); s < k; ++s) {
            invalid_count = (invalid_count + dp[s]) % MOD;
        }
        return invalid_count;
    }

public:
    int possibleStringCount(std::string word, int k) {
        if (word.empty()) {
            return 0;
        }

        const auto groups = buildConsecutiveGroups(word);
        const long long total_valid = calculateInitialTotal(groups);

        if (k <= static_cast<int>(groups.size())) {
            return static_cast<int>(total_valid);
        }

        const long long invalid = countInvalidSequences(groups, k);
        return static_cast<int>((total_valid - invalid + MOD) % MOD);
    }
};