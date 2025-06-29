class Solution {
public:
    // Helper function to count the number of products <= target for a given x1
    int countProductsLessThanOrEqual(const vector<int>& nums2, long long x1, long long target) {
        int n = nums2.size();
        int left = 0, right = n - 1;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long product = x1 * nums2[mid];
            
            if ((x1 >= 0 && product <= target) || (x1 < 0 && product > target)) {
                result = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // For positive x1, return count of elements <= target/x1
        // For negative x1, return count of elements >= target/x1 (since multiplying by negative reverses inequality)
        return x1 >= 0 ? result : n - result;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        long long answer = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;

            for (long long x1 : nums1) {
                if (x1 == 0) {
                    // All products will be 0, which are <= mid if mid >= 0
                    count += mid >= 0 ? nums2.size() : 0;
                    continue;
                }
                count += countProductsLessThanOrEqual(nums2, x1, mid);
            }

            if (count < k) {
                left = mid + 1;
            } else {
                answer = mid;
                right = mid - 1;
            }
        }

        return answer;
    }
};