class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int minimumX = 0;
        int maximumX = nums[nums.size() - 1];
        int result = INT_MAX;

        while (minimumX <= maximumX) {
            int x = minimumX + (maximumX - minimumX) / 2;

            // check if x is a valid result
            int totalPairs = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i + 1] - nums[i] <= x) {
                    totalPairs++;
                    i++;
                }
            }

            if (totalPairs < p) {
                minimumX = x + 1;
            } else {
                result=  x;
                maximumX = x - 1;
            }
        }

        return result;
    }
};