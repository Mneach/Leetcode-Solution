class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long result = 0, windowSum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            windowSum += nums[right];
            while (left <= right && windowSum * (right - left + 1) >= k) {
                windowSum -= nums[left++];
            }
            result += right - left + 1;
        }
        
        return result;
    }
};
