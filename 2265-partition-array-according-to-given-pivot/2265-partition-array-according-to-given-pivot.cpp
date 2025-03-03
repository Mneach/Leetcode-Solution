class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> answer;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) answer.push_back(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == pivot) answer.push_back(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > pivot) answer.push_back(nums[i]);
        }

        return answer;
    }
};