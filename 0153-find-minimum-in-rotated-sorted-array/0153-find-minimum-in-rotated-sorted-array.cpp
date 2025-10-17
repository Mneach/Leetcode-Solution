class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int currentNumber = nums[mid];
            
            int prevNumber = mid == 0 ? nums[nums.size() - 1] : nums[mid - 1];
            int nextNumber = mid == nums.size() - 1 ? nums[0] : nums[mid + 1];

            if (currentNumber <= prevNumber && currentNumber <= nextNumber) {
                result = currentNumber;
                break;
            }

            if (nums[left] > nums[right] && nums[left] <= nums[mid]) {
                // the minimum element should be in between mid and right pointer
                left = mid + 1;
            } else {
                // the minimum element should be in between left and mid pointer
                right = mid - 1;
            }
        }

        return result;
    }
};