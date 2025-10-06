class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int result = 0;

        if (goal == 0) {
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    count++;
                } else {
                    result += (1LL * count * (count + 1)) / 2;
                    count = 0;
                }
            }
            if (count != 0) {
                result += (1LL * count * (count + 1)) / 2;
            }
        } else {
            int count = 0;
            int left = 0;
            int right = 0;

            while (right < nums.size()) {
                goal -= nums[right];

                if (goal == 0) {
                    // move the left pointer
                    count = 0;
                    while (goal == 0) {
                        goal += nums[left];
                        left++;
                        count++;
                    }

                    result += count;
                } else {
                    result += count;
                }

                right++;
            }
        }

        return result;
    }
};