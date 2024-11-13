class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Sort nums to use binary search effectively
        sort(nums.begin(), nums.end());
        long long totalPairs = 0;

        // Lambda function to find the lower bound for a target in a subarray
        auto findLowerBound = [&](int start, int target) {
            int left = start, right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] >= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            return left;
        };

        // Iterate through each element to find valid pairs within range
        for (int i = 0; i < nums.size(); ++i) {
            // Find the range of elements that can pair with nums[i]
            int lowerBound = findLowerBound(i + 1, lower - nums[i]);
            int upperBound = findLowerBound(i + 1, upper - nums[i] + 1);

            // Add the count of valid pairs in the range [lower, upper]
            totalPairs += (upperBound - lowerBound);
        }

        return totalPairs;
    }
};
