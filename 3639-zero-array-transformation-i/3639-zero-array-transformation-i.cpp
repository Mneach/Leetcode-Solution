class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);  // Difference array for efficient range updates

        // Apply range increments using the difference array technique
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            diff[left]++;
            if (right + 1 < n) {
                diff[right + 1]--;
            }
        }

        // Compute the prefix sum to get actual operation counts
        int accumulated = 0;
        for (int i = 0; i < n; ++i) {
            accumulated += diff[i];
            if (accumulated < nums[i]) {
                return false;
            }
        }

        return true;
    }
};
