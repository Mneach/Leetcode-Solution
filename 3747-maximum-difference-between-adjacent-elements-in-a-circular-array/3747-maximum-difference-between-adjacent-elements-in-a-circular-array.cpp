class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int size = nums.size();
        int res = abs(nums[0] - nums[size - 1]);

        for (int i = 0; i < size - 1; i++) {
            res = max(res, abs(nums[i] - nums[i + 1]));
        }

        return res;
    }
};