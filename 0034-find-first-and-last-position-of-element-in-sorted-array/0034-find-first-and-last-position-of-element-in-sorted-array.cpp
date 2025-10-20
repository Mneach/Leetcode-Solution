class Solution {
private: 
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) {

                if (nums[mid] == target) {
                    result = mid;
                }
                
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    int upperBound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                if (nums[mid] == target) {
                    result = mid;
                }

                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int start = lowerBound(nums, target);
        int end = upperBound(nums, target);

        if (start == -1 || end == -1) {
            return {-1, -1};
        } else {
            return {start, end};
        }
    }
};