class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int answer = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) answer++;
            else nums[i - answer] = nums[i];
        }

        return nums.size() - answer;
    }
};