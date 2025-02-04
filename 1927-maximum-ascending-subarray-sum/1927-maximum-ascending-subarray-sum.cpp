class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int answer = 0;


        int temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] <= nums[i - 1]) {
                answer = max(answer, temp);
                temp = nums[i];
            } else {
                temp += nums[i];
            }
        }

        return max(answer, temp);
    }
};