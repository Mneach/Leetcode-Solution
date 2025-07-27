class Solution {
public:
    long long maxSubarrays(int n, std::vector<std::vector<int>>& conflictingPairs) {
        // Preprocess conflicting pairs to map each right endpoint to its left endpoints
        std::vector<std::vector<int>> right_endpoints(n + 1);
        for (const auto& pair : conflictingPairs) {
            int left = std::min(pair[0], pair[1]);
            int right = std::max(pair[0], pair[1]);
            right_endpoints[right].push_back(left);
        }

        long long total_subarrays = 0;
        std::vector<long long> top_two_lefts = {0, 0}; // tracks the two largest left endpoints
        std::vector<long long> bonus_values(n + 1, 0);

        for (int right = 1; right <= n; ++right) {
            // Update top two left endpoints for current right
            for (int left : right_endpoints[right]) {
                if (left > top_two_lefts[0]) {
                    top_two_lefts = {static_cast<long long>(left), top_two_lefts[0]};
                } else if (left > top_two_lefts[1]) {
                    top_two_lefts[1] = static_cast<long long>(left);
                }
            }

            // Count valid subarrays ending at current right
            total_subarrays += right - top_two_lefts[0];
            
            // Calculate bonus for potential swaps
            if (top_two_lefts[0] > 0) {
                bonus_values[top_two_lefts[0]] += top_two_lefts[0] - top_two_lefts[1];
            }
        }
        
        // Find the maximum bonus value
        long long max_bonus = *std::max_element(bonus_values.begin(), bonus_values.end());

        return total_subarrays + max_bonus;
    }
};