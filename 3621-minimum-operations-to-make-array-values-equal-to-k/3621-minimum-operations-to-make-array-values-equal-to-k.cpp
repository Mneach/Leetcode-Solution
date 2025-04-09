class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int answer = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k) return -1;

            if (i == 0 && nums[i] > k) {
                answer++;
            } else if (i > 0 && nums[i] != nums[i - 1]) {
                answer++;
            }
        }

        return answer;
    }
};