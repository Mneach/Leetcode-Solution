class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        
        // Compute prefix sum
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        vector<int> leftMaxIndex(n), rightMaxIndex(n), result(3);

        // Calculate best starting index for the left subarray
        for (int i = k, currentMaxSum = prefixSum[k] - prefixSum[0]; i < n; i++) {
            int currentSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            if (currentSum > currentMaxSum) {
                leftMaxIndex[i] = i + 1 - k;
                currentMaxSum = currentSum;
            } else {
                leftMaxIndex[i] = leftMaxIndex[i - 1];
            }
        }

        // Calculate best starting index for the right subarray
        rightMaxIndex[n - k] = n - k;
        for (int i = n - k - 1, currentMaxSum = prefixSum[n] - prefixSum[n - k]; i >= 0; i--) {
            int currentSum = prefixSum[i + k] - prefixSum[i];
            if (currentSum >= currentMaxSum) {
                rightMaxIndex[i] = i;
                currentMaxSum = currentSum;
            } else {
                rightMaxIndex[i] = rightMaxIndex[i + 1];
            }
        }

        // Find the maximum total sum by iterating over the middle subarray
        int maxSum = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            int leftIndex = leftMaxIndex[i - 1];
            int rightIndex = rightMaxIndex[i + k];

            int totalSum = 
                (prefixSum[i + k] - prefixSum[i]) +
                (prefixSum[leftIndex + k] - prefixSum[leftIndex]) +
                (prefixSum[rightIndex + k] - prefixSum[rightIndex]);

            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {leftIndex, i, rightIndex};
            }
        }

        return result;
    }
};
