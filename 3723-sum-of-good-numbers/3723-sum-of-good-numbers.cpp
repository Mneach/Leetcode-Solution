class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int answer = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i - k >= 0 && i + k < nums.size()) {

                if (nums[i] > nums[i - k] && nums[i] > nums[i + k]) {
                    answer += nums[i];
                }
            } else if (i - k >= 0) {
                if (nums[i] > nums[i - k]) {
                    answer += nums[i];
                }
            } else if (i + k < nums.size()) {
                if (nums[i] > nums[i + k]) {
                    answer += nums[i];
                }
            }
        }

        return answer;
    }
};