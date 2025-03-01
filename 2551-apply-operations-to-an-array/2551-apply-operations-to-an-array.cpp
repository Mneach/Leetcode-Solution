class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> answer;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        for (auto data : nums) {
            if (data > 0) {
                answer.push_back(data);
            }
        }

        while(answer.size() < nums.size()) {
            answer.push_back(0);
        }

        return answer;
    }
};