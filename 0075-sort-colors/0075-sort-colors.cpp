class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int current = 0;

        while (left < nums.size()) {
            if (nums[right] == current) {
                swap(nums[right], nums[left]);
                left++;
            }

            right++;

            if (right == nums.size()) {
                right = left;
                current++;
            }

            if (current == 2) break;
        }
    }
};