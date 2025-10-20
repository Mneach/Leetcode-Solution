class Solution {
private: 
    int findMostLeftPointer(vector<int> &nums, int left, int right, int target) {
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    int findMostRightPointer(vector<int> &nums, int left, int right, int target) {
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long result = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            int newLower = lower - nums[i];
            int newUpper = upper - nums[i];

            int left = i + 1;
            int right = nums.size() - 1;

            int mostLeftPointer = findMostLeftPointer(nums, left, right, newLower);
            int mostRightPointer = findMostRightPointer(nums, left, right, newUpper);

            if (mostLeftPointer == -1 || mostRightPointer == -1) {
                continue;
            }

            int count = (mostRightPointer - mostLeftPointer) + 1;
            result += count;
        }

        return result;
    }
};