class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> frequency;
        long long result = 0;
        int prefixSum = 0;

        frequency[0] = 1;

        for (int num : nums) {
            // Increase prefixSum if num % modulo == k
            if (num % modulo == k) {
                prefixSum++;
            }

            // Calculate how many times (prefixSum - k) % modulo has occurred
            int key = (prefixSum - k + modulo) % modulo;
            result += frequency[key];

            // Update frequency map for current prefixSum % modulo
            frequency[prefixSum % modulo]++;
        }

        return result;
    }
};
