class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size();
        
        // Check if it's possible to form a zero array after all queries
        if (!canFormZeroArray(nums, queries, right)) return -1;

        // Binary search to find the minimum number of queries needed
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFormZeroArray(nums, queries, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return left; // Return the earliest query index forming a zero array
    }

private:
    bool canFormZeroArray(const vector<int>& nums, const vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0); // Difference array for range updates
        
        // Apply the first k queries
        for (int i = 0; i < k; i++) {
            int start = queries[i][0], end = queries[i][1], val = queries[i][2];
            diff[start] += val;
            diff[end + 1] -= val;
        }
        
        // Compute the actual values and check if they meet the condition
        int accumulatedSum = 0;
        for (int i = 0; i < n; i++) {
            accumulatedSum += diff[i];
            if (accumulatedSum < nums[i]) return false;
        }
        
        return true;
    }
};